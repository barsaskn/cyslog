#include <rfc5424/facility.h>

Syslog_facility parse_syslog_facility(char* priority_number) {
    if (priority_number == NULL) {
        return -1; 
    }

    char* start = strchr(priority_number, '<');
    char* end = strchr(priority_number, '>');

    if (start == NULL || end == NULL) {
        return -1; 
    }

    char priority_number_str[end - start];
    strncpy(priority_number_str, start + 1, end - start - 1);
    priority_number_str[end - start - 1] = '\0';
    int priority_number_int = atoi(priority_number_str);
    return (Syslog_facility)(priority_number_int >> 3);
}