// C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Local headers
#include <input.h>
#include <intro.h>
#include <handler.h>

#define INTRO_FILE "raw_assets/tube_intro.txt"
#ifndef INTRO_FILE
    #include <tube_intro.h>
    #define INTRO_RAW "tube_intro_txt"
    #define INTRO_RAW_LEN INTRO_RAW##_len
#endif

#define BUFF_SIZE 256
#define ADDENDUM "Type 'help' to see a list of commands.\n"

int main(void) {
    #ifndef INTRO_FILE
        intro_from_mem(stdout, INTRO_RAW, INTRO_RAW_LEN, ADDENDUM);
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
