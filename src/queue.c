#include <queue.h>

Queue* init_queue(uint32_t data_size) {
    Queue* q = (Queue*)malloc(sizeof(Queue)); 
    if (q == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    q->size = data_size;
    q->data = (char **)malloc(data_size * sizeof(char *));
    if (q->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(q);
        exit(EXIT_FAILURE);
    }

    q->front = q->rear = 0;
    pthread_mutex_init(&q->mutex, NULL);
    pthread_cond_init(&q->cond_full, NULL);
    pthread_cond_init(&q->cond_empty, NULL);

    return q;
}

void enqueue(Queue *q, char* value) {
    pthread_mutex_lock(&q->mutex);
    while ((q->rear + 1) % q->size == q->front) {
        pthread_cond_wait(&q->cond_full, &q->mutex);
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % q->size;
    pthread_cond_signal(&q->cond_empty);
    pthread_mutex_unlock(&q->mutex);
}

char* dequeue(Queue *q) {
    char* value;
    pthread_mutex_lock(&q->mutex);
    while (q->front == q->rear) {
        pthread_cond_wait(&q->cond_empty, &q->mutex);
    }
    value = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    pthread_cond_signal(&q->cond_full);
    pthread_mutex_unlock(&q->mutex);
    return value;
}

void destroy_queue(Queue *q) {
    free(q->data);
    pthread_mutex_destroy(&q->mutex);
    pthread_cond_destroy(&q->cond_full);
    pthread_cond_destroy(&q->cond_empty);
    free(q);
}