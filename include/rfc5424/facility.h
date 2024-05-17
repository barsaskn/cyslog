#ifndef FACILITY_H
#define FACILITY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    KERN_MESSAGES = 0,
    USER_LEVEL_MESSAGES = 1,
    MAIL_SYSTEM = 2,
    SYSTEM_DAEMONS = 3,
    SECURITY_AUTH_MESSAGES_1 = 4,
    INTERNAL_MESSAGES = 5,
    LINE_PRINTER_SUBSYSTEM = 6,
    NETWORK_NEWS_SUBSYSTEM = 7,
    UUCP_SUBSYSTEM = 8,
    CLOCK_DAEMON_1 = 9,
    SECURITY_AUTH_MESSAGES_2 = 10,
    FTP_DAEMON = 11,
    NTP_SUBSYSTEM = 12,
    LOG_AUDIT = 13,
    LOG_ALERT = 14,
    CLOCK_DAEMON_2 = 15,
    LOCAL_USE_0 = 16,
    LOCAL_USE_1 = 17,
    LOCAL_USE_2 = 18,
    LOCAL_USE_3 = 19,
    LOCAL_USE_4 = 20,
    LOCAL_USE_5 = 21,
    LOCAL_USE_6 = 22,
    LOCAL_USE_7 = 23
} Syslog_facility ;

Syslog_facility parse_syslog_facility(char* priority_number);


#endif /* FACILITY_H */

