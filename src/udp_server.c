#include <udp_server.h>

Udp_server* init_udp_server(Queue* queue, int port) 
{
    Udp_server* udp_server = (Udp_server*)malloc(sizeof(Udp_server));
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        LOG_ERROR("Error openning socket");
    
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);


    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        LOG_ERROR("ERROR on binding");

    LOG_INFO("Udp server init on port %d", port);
    
    udp_server->sockfd = sockfd;
    udp_server->queue = queue;
    udp_server->listening = 0;
    udp_server->port = port;
    return udp_server;
}

void *listen_udp_server_thread(void* arg) {
    Udp_server * udp_server = (Udp_server *)arg;
    udp_server->listening = 1;
    char buffer[MAX_BUFFER_SIZE];
    memset(&buffer, 0, sizeof(MAX_BUFFER_SIZE));

    while (udp_server->listening) {
        int n;
        n = recvfrom(udp_server->sockfd, buffer, MAX_BUFFER_SIZE, MSG_WAITALL, NULL, NULL);
        if (n < 0) {
            break;
        }
        else if(n > 0) {
            buffer[n] = '\0';
            LOG_DEBUG("Client : %s", buffer);
            enqueue(udp_server->queue, buffer);
        } 
    }
    LOG_DEBUG("Listening thread exit");
    return NULL;
}

void listen_udp_server(Udp_server* udp_server) {
    int rc;
    rc = pthread_create(&udp_server->listening_thread, NULL, listen_udp_server_thread, (void *)udp_server);
    if (rc) {
        LOG_ERROR("ERROR; return code from pthread_create() is %d\n", rc);
    }
}

void close_udp_server(Udp_server* udp_server) {
    LOG_DEBUG("Closing port %d", udp_server->sockfd);
    udp_server->listening = 0;
    shutdown(udp_server->sockfd, SHUT_RDWR);
    close(udp_server->sockfd);
    pthread_join(udp_server->listening_thread, NULL);
    free(udp_server);
}

