// C standard library
#include <stdio.h>
#include <stdlib.h>

// Public functions
void intro_from_file(FILE *outStream, char *introFileName, char *addendum) {
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

void intro_from_mem(FILE *outStream, unsigned char *introFile, unsigned int introFileLen, char *addendum) {
    char *readBuff = (char*) introFile;
    readBuff[introFileLen - 1] = '\0';
    fprintf(outStream, "%s\n%s", readBuff, addendum);
}