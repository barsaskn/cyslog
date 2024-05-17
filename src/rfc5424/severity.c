#include <rfc5424/severity.h>

Syslog_severity parse_syslog_severity(char* priority_number) {
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
    int severity = priority_number_int & 0x07;

    if (severity == 0) {
        return -1; 
    }
    
    switch (severity) {
        case 0: return EMERGENCY;
        case 1: return ALERT;
        case 2: return CRITICAL;
        case 3: return ERROR;
        case 4: return WARNING;
        case 5: return NOTICE;
        case 6: return INFORMATIONAL;
        case 7: return DEBUG;
        default: return -1;
    }
}
