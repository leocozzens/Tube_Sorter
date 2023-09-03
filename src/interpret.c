// C standard library
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
// Local headers
#include <interpret.h>

#define MAX_CMD_SIZE 10

#define STRINGIZE(arg) #arg
#define X(command, desc, usage) STRINGIZE(command),  // Alternatively [cmd] = STRINGIZE[cmd], can be used if enum is not ordered from 0-max
static char *checkList[] = {
    COMMAND_LIST
};
#undef X

// Static functions
static void str_to_upper(char *in, char *out, int strLen) {
    for(int i = 0; i < strLen; i++) out[i] = toupper(in[i]);
}

static bool verify_has_depth(int depth, char *buffer) {
    unsigned int buffLen = strlen(buffer);
    unsigned int i = 0;
    unsigned int args = 0;
    while(args < depth && i < buffLen) {
        if(buffer[i++] == ' ') args++;
    }
    if(buffer[i] != '\0') return false;
    return true;
}

static bool is_valid(CommandType type, char *buffer) {
    switch(type) {
        case NONE:
            return false;
        case DONE:
        case HELP:
            return verify_has_depth(0, buffer + strlen(checkList[type]));
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

// Public functions
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