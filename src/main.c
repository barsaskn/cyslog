#include <stdio.h>
#include <queue.h>
#include <udp_server.h>
#include <rfc5424_parser.h>
#include <unistd.h>

int main() {
    Queue* queue = init_queue(100);
    Udp_server* udp_server = init_udp_server(queue, 8080);
    listen_udp_server(udp_server);
    close_udp_server(udp_server);
    //while(1);
}