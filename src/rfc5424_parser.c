// rfc5424_parser.c
#include <rfc5424_parser.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Syslog_message* parse_rfc5424(char* syslog_message) {
    Syslog_message* msg = (Syslog_message*)malloc(sizeof(Syslog_message));
    if (!msg) {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }

    memset(msg, 0, sizeof(Syslog_message)); 

    char* message_copy = strdup(syslog_message);
    if (!message_copy) {
        fprintf(stderr, "Memory allocation error\n");
        free(msg);
        return NULL;
    }

    char* token = strchr(message_copy, '>');
    if (!token || message_copy[0] != '<') {
        fprintf(stderr, "Invalid syslog message\n");
        free(message_copy);
        free(msg);
        return NULL;
    }
    size_t priority_len = token - message_copy + 1;
    msg->priority = strndup(message_copy, priority_len);
    
    Syslog_severity severity = parse_syslog_severity(msg->priority);
    char* current_position = token + 1;

    token = strtok(current_position, " ");
    if (!token) {
        fprintf(stderr, "Invalid syslog message\n");
        free(message_copy);
        free_syslog_message(msg);
        return NULL;
    }
    msg->version = strdup(token);

    char* fields[6];
    for (int i = 0; i < 6; i++) {
        token = strtok(NULL, " ");
        if (!token) {
            fprintf(stderr, "Invalid syslog message\n");
            free(message_copy);
            free_syslog_message(msg);
            return NULL;
        }
        fields[i] = token;
    }

    msg->timestamp = strdup(fields[0]);
    msg->hostname = strdup(fields[1]);
    msg->appname = strdup(fields[2]);
    msg->procid = strdup(fields[3]);
    msg->msgid = strdup(fields[4]);

    if (strcmp(fields[5], "-") != 0) {
        msg->structured_data = strdup(fields[5]);
    } else {
        msg->structured_data = NULL;
    }

    token = strtok(NULL, "");
    if (token) {
        msg->message = strdup(token);
    } else {
        msg->message = NULL;
    }

    free(message_copy);
    return msg;
}

void free_syslog_message(Syslog_message* msg) {
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
