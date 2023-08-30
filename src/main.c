#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

static void determine_type();

static bool check_input(char *buffer, int buffSize) {
        if(buffer[0] == 'D' || buffer[0] == 'd') return true;
        if(strncmp(buffer, "help", buffSize) == 0) {
            printf("find: finds tube\ncompare: compares two tube lists\ncreate: \n open: \n sort: ");
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