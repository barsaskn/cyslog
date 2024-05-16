// rfc5424_parser.h
#ifndef RFC5424_PARSER_H
#define RFC5424_PARSER_H

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
} SyslogMessage;

SyslogMessage* parse_rfc5424(char* syslog_message);

void free_syslog_message(SyslogMessage* msg);

#endif // RFC5424_PARSER_H
