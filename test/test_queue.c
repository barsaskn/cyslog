#include <test_queue.h>

int enqueue_dequeue_test() {
    printf("*** QUEUE TEST STARTING ***\n");
    Queue* q = init_queue(32);
    char enqueue_char[] = "test";
    enqueue(q, enqueue_char);
    char* dequeue_char = dequeue(q);
    assert(strcmp(dequeue_char, enqueue_char) == 0);
    destroy_queue(q);
    printf("*** QUEUE TEST SUCCESS ***");
    return 1;
}

void run_all_queue_tests() {
    enqueue_dequeue_test();
}