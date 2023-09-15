// C standard library
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// Local headers
#include <commands.h>
#define BUFF_SIZE 256
#define DONE_STR "Exiting program..."

#define STRINGIZE(arg) #arg
#define X(command, desc, usage) printf("\n" STRINGIZE(command:) " "desc"\nUSAGE - " usage "\n", STRINGIZE(command));

// Public functions
void operation_print_help(void) {
    COMMAND_LIST;
}

#undef X

void operation_done(void) {
    printf("%s\n", DONE_STR);
}

void operation_find(char *buffer) {    
    FILE *inFile = fopen("tubenumbers_box3replated.txt", "r");
    char inBuffer[BUFF_SIZE];
    int column, row = 0;
    char *search = buffer + strlen("find") + 1;
    bool found = false;
    while(fgets(inBuffer, BUFF_SIZE, inFile)) {
        column = 1;
        row++;
        int i = 0;
        while(i < strlen(inBuffer)) {
            if(inBuffer[i] == ',') {
                i++;
                column++;
                continue;
            }
            if(strncmp(inBuffer + i, search, 3) == 0) {
                found = true;
                break;
            }
            i+= 3;
        }
        if(found) {
            printf("row: %d, column: %d\n", row, column);
            break;
        }
    }
}

void operation_compare(void) {
    FILE *f1 = fopen("tubenumbers_box3.txt", "r");
    FILE *f2 = fopen("tubenumbers_box3replated.txt", "r");
    char f1Buff[BUFF_SIZE];
    char f2Buff[BUFF_SIZE];
    int column, row = 0;
    while(fgets(f1Buff, BUFF_SIZE, f1)) {
        column = 1;
        row++;
        int i = 0;
        printf("Analyzing row %d\n", row);
        while(i < strlen(f1Buff)) {
            if(f1Buff[i] == ',') {
                i++;
                column++;
                continue;
            }
            bool found = false;
            while(fgets(f2Buff, BUFF_SIZE, f2)) {
                int j = 0;
                while(j < strlen(f2Buff)) {
                    if(f2Buff[j] == ',') {
                        j++;
                        continue;
                    }
                    if(strncmp(f1Buff + i, f2Buff + j, 3) == 0) {
                        found = true;
                    }
                    j += 3;
                }
            }
            if(!found) {
                char out[4];
                out[3] = '\0';
                strncpy(out, f1Buff + i, 3);
                printf("missing: %s\n", out);
            }
            i += 3;
            rewind(f2);
        }
    }
}