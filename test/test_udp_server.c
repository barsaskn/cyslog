#include <test_udp_server.h>

void udp_client(char *message) {
    int sockfd;
    struct sockaddr_in server_addr;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("sendto");
        exit(1);
    }
    
    close(sockfd);
}

int run_udp_server_test() {
    Queue* queue = init_queue(100);
    Udp_server* udp_server = init_udp_server(queue, 8080);
    listen_udp_server(udp_server);
    close_udp_server(udp_server);
    destroy_queue(queue);
    return 1;
}

int check_server_data_from_queue() {
    Queue* queue = init_queue(100);
    Udp_server* udp_server = init_udp_server(queue, PORT);
    listen_udp_server(udp_server);
    char* test = "test";
    udp_client(test);
    char* dequeue_test = dequeue(queue);
    assert(strcmp(dequeue_test, test) == 0);
    close_udp_server(udp_server);
    destroy_queue(queue);
    return 1;
}

void run_all_udp_server_tests() {
    printf("*** UDP SERVER TEST STARTING ***\n");
    run_udp_server_test();
    //check_server_data_from_queue();
    printf("*** UDP SERVER TEST SUCCESS ***\n");
}