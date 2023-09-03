// Local headers
#include <handler.h>
#include <interpret.h>
#include <operations.h>

// Static functions
static void fail(CommandType failType) {
    switch(failType) {
        case NONE:
            break;
        case DONE:
            break;
        case HELP:
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
}

// Public functions
bool handle_input(char *buffer) {
    TypeInfo inputType = interpret_type(buffer);
    if(inputType.offSet == 0) {
        fail(inputType.type);
        goto END;
    }
    switch(inputType.type) {
        case NONE:
            goto END;
        case DONE:
            return false;
        case HELP:
            operation_print_help();
            break;
        case FIND:
            operation_find(buffer);
            break;
        case COMPARE:
            operation_compare();
            break;
        case CREATE:
            break;
        case OPEN:
            break;
        case SORT:
            break;
    }
    END:
    return true;
}