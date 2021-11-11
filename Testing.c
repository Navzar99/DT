//
// Created by razva on 30/10/2021.
//

#include <dirent.h>
#include "Testing.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

char **FileList;

void readFromFile(char* fileName)
{
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL) {
        printf("Can't open file\n\n");
        return;
    }

    code = malloc(1000);

    while ((c = fgetc(file)) != EOF)
    {
        code[n++] = (char) c;
    }

    code[n] = '\0';
    printf("%s\n", code);
}

void getFilesFromDir()
{
    char testDir[] = "../Tests/";

    // Gets lists of Tests
    DIR *d;
    struct dirent *dir;
    d = opendir(testDir);
    if (d) {
        while ((dir = readdir(d)) != NULL)
        {
            unsigned fileNameLength = strlen(dir->d_name);
            unsigned dirNameLength = strlen(testDir);

            if(strcmp(dir->d_name, ".")!=0 && strcmp(dir->d_name, "..")!=0) {
                char *filePath = (char *) calloc(fileNameLength + dirNameLength, sizeof(char));
                strcpy(filePath, testDir);
                strcat(filePath, dir->d_name);

                printf("Opened file: %s\n", filePath);
                readFromFile(filePath);
                if (filePath != NULL) free(filePath);
            }
        }
        closedir(d);
    }
}