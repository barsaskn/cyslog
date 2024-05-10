#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <log.h>
#include <queue.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    int listening;
    int port;
    Queue* queue;
} Udp_server;

Udp_server* init_udp_server(Queue* queue, int port);

void listen_udp_server(Udp_server* udp_server);

void close_udp_server(Udp_server* udp_server);

#endif /* UDP_SERVER_H */