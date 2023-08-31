#ifndef INTERPRET_H
#define INTERPRET_H

typedef enum {
    FAIL = -1,
    DONE,
    HELP,
    FIND,
    COMPARE,
    CREATE,
    OPEN,
    SORT
} CommandType;

CommandType determine_type(char *buffer);

#endif