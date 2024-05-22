#include "rfc5424/timestamp_rfc3339_parser.h"


struct tm* parse_rfc3339(const char *rfc3339_date) {
    struct tm* tm = (struct tm*)malloc(sizeof(struct tm));

    if (strptime(rfc3339_date, "%Y-%m-%dT%H:%M:%S", tm) == NULL) {
        free(tm);
        return NULL; 
    }

    return tm;
}
