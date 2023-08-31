#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <interpret.h>

#define INTRO_FILE "tube_intro.txt"
#define BUFF_SIZE 256

#define ADDENDUM "Type 'help' to see a list of commands.\n"

static void clear_stdin(void) {
    int c;
    do { c = fgetc(stdin); } while(c != '\n' || c != EOF);
}

static void get_input(char *buffer, int buffSize, FILE *inStream) {
    fgets(buffer, buffSize, inStream);
    char *newLine = strrchr(buffer, '\n');
    if(newLine == NULL) clear_stdin();
    else *newLine = '\0';
}

static void print_intro(FILE *outStream, char *introFileName, char *addendum) {
    FILE *introFile = fopen(introFileName, "r");
    fseek(introFile, 0, SEEK_END);
    int fSize = ftell(introFile);
    fseek(introFile, 0, SEEK_SET);

    char *readBuff = malloc(fSize + 1);
    fread(readBuff, fSize, 1, introFile);
    fclose(introFile);
    readBuff[fSize] = '\0';
    fprintf(outStream, "%s\n%s", readBuff, addendum);
    free(readBuff);
}

static bool check_input(char *buffer, int buffSize) {
        switch(determine_type(buffer)) {
            case FAIL:
                break;
            case DONE:
                return true;
            case HELP:
                printf("find: finds tube\ncompare: compares two tube lists\ncreate: \n open: \n sort: ");
                break;
            case FIND:
                FILE *inFile = fopen("tubenumbers_box3replated.txt", "r");
                char inBuffer[BUFF_SIZE];
                int column, row = 0;
                char *search = buffer + strlen("find") + 1;
                bool found = false;
                while(fgets(inBuffer, buffSize, inFile)) {
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
                break;
            case COMPARE:
                {    
                    FILE *f1 = fopen("tubenumbers_box3.txt", "r");
                    FILE *f2 = fopen("tubenumbers_box3replated.txt", "r");
                    char f1Buff[BUFF_SIZE];
                    char f2Buff[BUFF_SIZE];
                    int column, row = 0;
                    while(fgets(f1Buff, buffSize, f1)) {
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
                            while(fgets(f2Buff, buffSize, f2)) {
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
                break;
            case CREATE:
                break;
            case OPEN:
                break;
            case SORT:
                break;
        }
        return false;
}

int main(void) {
    bool run = true;
    char buffer[BUFF_SIZE];
    print_intro(stdout, INTRO_FILE, ADDENDUM);
    while(run) {
        printf(">> ");
        get_input(buffer, BUFF_SIZE, stdin);
        if(check_input(buffer, BUFF_SIZE)) break;
    }
}
