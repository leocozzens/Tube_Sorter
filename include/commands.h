#ifndef COMMANDS_H
#define COMMANDS_H

#define NO_ARG "%s"
#define SINGLE_ARG "%s [FILE]"
#define TWO_ARG "%s [FILES]..."
#define THREE_ARG "%s [FILES]... | [TUBES]..."

#define COMMAND_LIST \
    X(DONE, "Exits the program", NO_ARG) \
    X(HELP, "Lists available commands with accompanying descriptions", SINGLE_ARG) \
    X(FIND, "Finds tube", THREE_ARG) \
    X(COMPARE, "Compares multiple tube lists", TWO_ARG) \
    X(CREATE, "Creates new tube list", TWO_ARG) \
    X(OPEN, "Opens existing tube list", SINGLE_ARG) \
    X(SORT, "Sorts existing tube list", TWO_ARG)
#endif