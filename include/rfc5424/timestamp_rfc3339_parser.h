#ifndef RFC3339_PARSER_H
#define RFC3339_PARSER_H

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif

#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct tm*  parse_rfc3339(const char *rfc3339_date);

#endif /* RFC3339_PARSER_H */
