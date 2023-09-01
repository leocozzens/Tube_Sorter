// C standard library
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
// Local headers
#include <interpret.h>

#define CHECK_LAST_OP(__type, __len, __buffer) if(__buffer[__len] == ' ') return false
#define MAX_CMD_SIZE 10

#define STRINGIZE(arg) #arg
#define X(cmd) STRINGIZE(cmd),  // Alternatively [cmd] = STRINGIZE[cmd], can be used if enum is not ordered from 0-max
static char *checkList[] = {
    COMMAND_LIST
};

static void str_to_upper(char *in, char *out, int strLen) {
    for(int i = 0; i < strLen; i++) out[i] = toupper(in[i]);
}

static bool is_valid(CommandType type, char *buffer) {
    switch(type) {
        case NONE:
            return false;
        case DONE:
        case HELP:
            CHECK_LAST_OP(type, strlen(checkList[type]), buffer);
            break;
        case FIND:
            break;
        case COMPARE:
            break;
        case CREATE:
            break;
        case OPEN:
            break;
        case SORT:
            break;
    }
    return true;
}

TypeInfo interpret_type(char *buffer) {
    unsigned int buffLen = strlen(buffer);
    TypeInfo retInfo = { NONE, 0 };
    if(buffLen == 0) return retInfo;

    char upperVer[MAX_CMD_SIZE];
    for(CommandType i = 0; i < sizeof(checkList) / sizeof(char*); i++) {
        unsigned int itemLen = strlen(checkList[i]);
        if(buffLen < itemLen) continue;
        if(buffer[itemLen] != '\0' && buffer[itemLen] != ' ') continue;

        str_to_upper(buffer, upperVer, itemLen);
        if(strncmp(upperVer, checkList[i], itemLen) == 0) {
            retInfo.type = i;
            if(is_valid(retInfo.type, buffer)) retInfo.offSet = itemLen;
            return retInfo;
        }
    }
    return retInfo;
}

// TokenList tokenize