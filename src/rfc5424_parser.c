// rfc5424_parser.c
#include "rfc5424_parser.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

SyslogMessage* parse_rfc5424(char* syslog_message) {
    SyslogMessage* msg = malloc(sizeof(SyslogMessage));
    if (!msg) {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }
    
    char* token = strtok(syslog_message, " ");
    if (!token) {
        fprintf(stderr, "Invalid syslog message\n");
        free(msg);
        return NULL;
    }
    
    msg->priority = strdup(token);
    token = strtok(NULL, " ");
    msg->version = strdup(token);
    token = strtok(NULL, " ");
    msg->timestamp = strdup(token);
    token = strtok(NULL, " ");
    msg->hostname = strdup(token);
    token = strtok(NULL, " ");
    msg->appname = strdup(token);
    token = strtok(NULL, " ");
    msg->procid = strdup(token);
    token = strtok(NULL, " ");
    msg->msgid = strdup(token);
    token = strtok(NULL, " ");
    if (token && strcmp(token, "-") != 0) {
        msg->structured_data = strdup(token);
    } else {
        msg->structured_data = NULL;
    }
    token = strtok(NULL, "");
    if (token) {
        msg->message = strdup(token);
    } else {
        msg->message = NULL;
    }
    
    return msg;
}

void free_syslog_message(SyslogMessage* msg) {
    if (!msg) return;
    free(msg->priority);
    free(msg->version);
    free(msg->timestamp);
    free(msg->hostname);
    free(msg->appname);
    free(msg->procid);
    free(msg->msgid);
    free(msg->structured_data);
    free(msg->message);
    free(msg);
}
