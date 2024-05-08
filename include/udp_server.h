#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <log.h>

#define MAX_BUFFER_SIZE 1024

int init_udp_server(int port);

#endif /* UDP_SERVER_H */