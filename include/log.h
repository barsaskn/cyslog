#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

static inline void get_current_timestamp(char* buffer, size_t buffer_size) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    
    struct tm* t = localtime(&tv.tv_sec);

    strftime(buffer, buffer_size, "[%Y-%m-%d %H:%M:%S", t);
    size_t len = strlen(buffer);
    snprintf(buffer + len, buffer_size - len, ".%03d]", tv.tv_usec / 1000);
}

#define LOG_DEBUG(msg, ...) do { \
    char timestamp[30]; \
    get_current_timestamp(timestamp, sizeof(timestamp)); \
    printf("%s [" ANSI_COLOR_BLUE "debug" ANSI_COLOR_RESET "] " msg "\n", timestamp, ##__VA_ARGS__); \
} while (0)

#define LOG_INFO(msg, ...) do { \
    char timestamp[30]; \
    get_current_timestamp(timestamp, sizeof(timestamp)); \
    printf("%s [" ANSI_COLOR_GREEN "info" ANSI_COLOR_RESET "] " msg "\n", timestamp, ##__VA_ARGS__); \
} while (0)

#define LOG_WARNING(msg, ...) do { \
    char timestamp[30]; \
    get_current_timestamp(timestamp, sizeof(timestamp)); \
    printf("%s [" ANSI_COLOR_YELLOW "warning" ANSI_COLOR_RESET "] " msg "\n", timestamp, ##__VA_ARGS__); \
} while (0)

#define LOG_ERROR(msg, ...) do { \
    char timestamp[30]; \
    get_current_timestamp(timestamp, sizeof(timestamp)); \
    printf("%s [" ANSI_COLOR_RED "error" ANSI_COLOR_RESET "] " msg "\n", timestamp, ##__VA_ARGS__); \
} while (0)

#endif /* LOG_H */
