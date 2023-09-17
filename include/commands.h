#ifndef COMMANDS_H
#define COMMANDS_H

#define SEPARATOR "/"

#define NO_ARG "%s"
#define SINGLE_ARG "%s [FILES]..."
#define TWO_ARG "%s [FILES]... " SEPARATOR " [TUBES]..."

#define COMMAND_LIST \
    X(DONE, "Exits the program", NO_ARG) \
    X(HELP, "Lists available commands with accompanying descriptions", NO_ARG) \
    X(FIND, "Finds tube", TWO_ARG) \
    X(COMPARE, "Compares multiple tube lists", SINGLE_ARG) \
    X(CREATE, "Creates new tube list", SINGLE_ARG) \
    X(OPEN, "Opens existing tube list", SINGLE_ARG) \
    X(SORT, "Sorts existing tube list", SINGLE_ARG)

#endif