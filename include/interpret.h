#ifndef INTERPRET_H
#define INTERPRET_H

#include <commands.h>
#define X(cmd) cmd,

typedef enum {
    FAIL = -1,
    COMMAND_LIST
} CommandType;
#undef X

CommandType interpret_type(char *buffer);

#endif