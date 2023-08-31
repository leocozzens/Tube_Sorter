// C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Local headers
#include <input.h>
#include <intro.h>
#include <handler.h>

// #define INTRO_FILE "raw_assets/tube_intro.raw"
#ifndef INTRO_FILE
    #include <raw_tube_intro.h>
    #define INTRO_RAW raw_assets_tube_intro_raw
    #define CAT(x, y) x ## y
    #define RAW_LEN(raw) CAT(raw, _len)
#endif

#define BUFF_SIZE 256
#define ADDENDUM "Type 'help' to see a list of commands.\n"

int main(void) {
    #ifndef INTRO_FILE
        intro_from_mem(stdout, INTRO_RAW, RAW_LEN(INTRO_RAW), ADDENDUM);
    #else
        intro_from_file(stdout, INTRO_FILE, ADDENDUM);
    #endif
    bool run;
    char buffer[BUFF_SIZE];
    do {
        printf(">> ");
        input_get(buffer, BUFF_SIZE, stdin);
        run = handle_input(buffer);
    } while(run);
}
