// C standard library
#include <string.h>
#include <ctype.h>
// Local headers
#include <interpret.h>

static char *checkList[] = {
    "done",
    "help",
    "find",
    "compare",
    "create",
    "open",
    "sort"
};

static int min(int first, int second) {
    return (first < second) ? first : second;
}

CommandType determine_type(char *buffer) {
    int buffLen = strlen(buffer);
    for(int i = 0; i < sizeof(checkList) / sizeof(char*); i++) {
        if(strncmp(buffer, checkList[i], min(buffLen, strlen(checkList[i]))) == 0) {
            return (CommandType) i;
        }
    }
    return FAIL;
}