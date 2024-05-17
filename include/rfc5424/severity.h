#ifndef SEVERITY_H
#define SEVERITY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    EMERGENCY = 0,
    ALERT = 1,
    CRITICAL = 2,
    ERROR = 3,
    WARNING = 4,
    NOTICE = 5,
    INFORMATIONAL = 6,
    DEBUG = 7
} Syslog_severity;

Syslog_severity parse_syslog_severity(char* priority_number);

#endif /* SEVERITY_H */

