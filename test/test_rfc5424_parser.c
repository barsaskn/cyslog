#include <test_rfc5424_parser.h>

void parse_test() {
    char* test_packet = "<134>1 2024-05-16T12:00:00.000Z mymachine.example.com su - ID47 - BOM'su root' failed for lonvick on /dev/pts/8";
    Syslog_message* test_syslog_message =  parse_rfc5424(test_packet);
    assert(test_syslog_message->severity == INFORMATIONAL);
    assert(test_syslog_message->facility == LOCAL_USE_0);
    assert(strcmp(test_syslog_message->version, "1") == 0);
    //assert(strcmp(test_syslog_message->timestamp, "2024-05-16T12:00:00.000Z") == 0);
    assert(strcmp(test_syslog_message->hostname, "mymachine.example.com") == 0);
    assert(strcmp(test_syslog_message->appname, "su") == 0);
    assert(strcmp(test_syslog_message->msgid, "ID47") == 0);
    assert(strcmp(test_syslog_message->message, "BOM'su root' failed for lonvick on /dev/pts/8") == 0);
    free_syslog_message(test_syslog_message);
}

void run_all_rfc5424_parser_tests() {
    printf("*** RFC5424 PARSER TEST STARTING ***\n");
    parse_test();
    printf("*** RFC5424 PARSER TEST SUCCESS ***\n");
}