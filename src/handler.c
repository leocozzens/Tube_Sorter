// Local headers
#include <handler.h>
#include <interpret.h>
#include <operations.h>

bool handle_input(char *buffer) {
    switch(interpret_type(buffer)) {
        case FAIL:
            break;
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
    return true;
}