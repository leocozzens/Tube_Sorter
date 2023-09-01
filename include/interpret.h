#ifndef INTERPRET_H
#define INTERPRET_H

#include <commands.h>
#define X(cmd) cmd,

typedef enum {
    NONE = -1,
    COMMAND_LIST
} CommandType;
#undef X

typedef struct {
    CommandType type;
    unsigned int offSet;
} TypeInfo;

TypeInfo interpret_type(char *buffer);

#endif