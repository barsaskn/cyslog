#include <test_queue.h>
#include <test_udp_server.h>

int main() {
    run_all_queue_tests();
    run_all_udp_server_tests();
}