#include <stdio.h>
#include <queue.h>
#include <assert.h>
#include <string.h>

int main() {
    printf("*** QUEUE TEST STARTING ***\n");
    Queue* q = init_queue(32);
    char enqueue_char[] = "test";
    enqueue(q, enqueue_char);
    char* dequeue_char = dequeue(q);
    assert(strcmp(dequeue_char, enqueue_char) == 0);
    destroy_queue(q);
    printf("*** QUEUE TEST SUCCESS ***");
}