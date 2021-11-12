#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

#include "Parser.h"
//#include "Testing.h" // TODO: comment before submitting


void printArgs(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i)
    {
        printf("%d : %s\n", i, argv[i]);
    }
    printf("\n\n");
}

void parseFile(char *fileName)
{
    printf("File name: %s", fileName);
    FILE *file = fopen(fileName, "rb");
    size_t n = 0;

    if (file == NULL) {
        printf("Can't open file\n\n");
        return;
    }

    uint8_t response;

    uint32_t ch;

    while ((ch = fgetc(file)) != EOF)
    {
        response = at_command_parse(ch);
    }
    printResponse(response);
}

void mainFunction(int argc, char **argv)
{
    printArgs(argc, argv);

    uint32_t fileNameLength;
    uint32_t i =1;

    fileNameLength = strlen(argv[i]);
    char fileName[fileNameLength];
    strcpy(fileName, argv[i]);
    printf("%s\n", fileName);
    parseFile(fileName);
    printf("\n\n");
}

void test()
{

}

int main(int argc, char *argv[])
{

    mainFunction(argc, argv);
    // getFilesFromDir();  // TODO: comment before submitting

    return 0;
}
