#ifndef LOG_H
#define LOG_H

#include <stdio.h>

// ANSI escape codes for colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define LOG_DEBUG(msg, ...) printf(ANSI_COLOR_BLUE "[DEBUG] "  ANSI_COLOR_RESET msg "\n", ##__VA_ARGS__)
#define LOG_INFO(msg, ...) printf(ANSI_COLOR_GREEN "[INFO] "  ANSI_COLOR_RESET msg "\n", ##__VA_ARGS__)
#define LOG_WARNING(msg, ...) printf(ANSI_COLOR_YELLOW "[WARNING] " ANSI_COLOR_RESET msg "\n", ##__VA_ARGS__)
#define LOG_ERROR(msg, ...) printf(ANSI_COLOR_RED "[ERROR] " ANSI_COLOR_RESET msg "\n", ##__VA_ARGS__)

#endif /* LOG_H */

