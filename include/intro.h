#ifndef INTRO_H
#define INTRO_H

void intro_from_file(FILE *outStream, char *introFileName, char *addendum);
void intro_from_mem(FILE *outStream, unsigned char *introFile, unsigned int introFileLen, char *addendum);

#endif