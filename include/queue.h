#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

typedef struct {
    char **data;
    int size;
    int front, rear;
    pthread_mutex_t mutex;
    pthread_cond_t cond_full;
    pthread_cond_t cond_empty;
} Queue;

Queue* init_queue(uint32_t data_size);

void enqueue(Queue *q, char* value);

char* dequeue(Queue *q);

void destroy_queue(Queue *q);

#endif /* QUEUE_H */