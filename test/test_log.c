#include <test_log.h>

void simple_log_test() {
    int i = 1;
    LOG_DEBUG("Debug Message: %d", i);
    i++;
    LOG_INFO("INFO Message: %d", i);
    i++;
    LOG_WARNING("WARNING Message: %d", i);
    i++;
    LOG_ERROR("ERROR Message: %d", i);
    i++;
}

void* multithread_log_test_thread() {
    LOG_DEBUG("Debug Message");
    LOG_INFO("INFO Message");
    LOG_WARNING("WARNING Message");
    LOG_ERROR("ERROR Message");
    return NULL;
}

void multithread_log_test() {
    const int NUM_THREADS = 5;
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, multithread_log_test_thread, NULL) != 0) {
            perror("Failed to create thread");
            return;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return;
        }
    }
}

void run_all_log_tests() {
    printf("*** LOG TEST STARTING ***\n");
    simple_log_test();
    multithread_log_test();
    printf("*** LOG TEST SUCCESS ***\n");
}
