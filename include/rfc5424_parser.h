#ifndef RFC5424_PARSER_H
#define RFC5424_PARSER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <log.h>
#include <rfc5424/severity.h>
#include <rfc5424/facility.h>

typedef struct {
    char* priority;
    char* version;
    char* timestamp;
    char* hostname;
    char* appname;
    char* procid;
    char* msgid;
    char* structured_data;
    char* message;
} Syslog_message;

Syslog_message* parse_rfc5424(char* syslog_message);

void free_syslog_message(Syslog_message* msg);

#endif // RFC5424_PARSER_H
