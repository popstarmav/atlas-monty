#include "helper.h"
#include <ctype.h>

/* Define the is_numeric function */
int is_numeric(const char *str) {
    if (!str)
        return 0;

    for (int i = 0; str[i]; i++) {
        if (!isdigit((unsigned char)str[i]) && str[i] != '-')
            return 0;
    }
    return 1;
}
