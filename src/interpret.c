// C standard library
#include <string.h>
#include <ctype.h>
// Local headers
#include <interpret.h>
#define MAX_CMD_SIZE 10

#define STRINGIZE(arg) #arg
#define X(cmd) STRINGIZE(cmd),  // Alternatively [cmd] = STRINGIZE[cmd], can be used if enum is not ordered from 0-max
static char *checkList[] = {
    COMMAND_LIST
};

static void str_to_upper(char *in, char *out, int strLen) {
    for(int i = 0; i < strLen; i++) out[i] = toupper(in[i]);
}

CommandType interpret_type(char *buffer) {
    int buffLen = strlen(buffer);
    if(buffLen == 0) return FAIL;
    char upperVer[MAX_CMD_SIZE];
    for(CommandType i = 0; i < sizeof(checkList) / sizeof(char*); i++) {
        int itemLen = strlen(checkList[i]);
        if(buffLen < itemLen) continue;
        if(buffer[itemLen] != '\0' && buffer[itemLen] != ' ') continue;
        str_to_upper(buffer, upperVer, itemLen);
        if(strncmp(upperVer, checkList[i], itemLen) == 0) return i;
    }
    return FAIL;
}

// TokenList tokenize