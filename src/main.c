#include <stdio.h>
#include <queue.h>
#include <udp_server.h>

int main() {
    Queue* q = init_queue(32);
    init_udp_server(8080);
    init_udp_server(8081);
    init_udp_server(8082);
}