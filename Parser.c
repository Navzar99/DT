//
// Created by razva on 30/10/2021.
//

#include <stdio.h>
#include "Parser.h"

void printResponse(uint8_t response)
{
    switch (response) {
        case STATE_MACHINE_READY_OK: {
            printf("\n\nResult: READY OK\n\n");
            break;
        }
//        case STATE_MACHINE_READY_WITH_ERROR: {
//            printf("READY WITH ERROR\n\n");
//            break;
//        }
        default: {
            printf("\n\nResult: READY WITH ERROR\n\n");
            break;
        }
    }
}

void printState(uint8_t current_character, uint32_t st)
{
    if (current_character == CR)
        printf("char: CR  state: %d\n", st);
    else if (current_character == LF)
        printf("char: LF  state: %d\n", st);
    else
        printf("char: %c   state: %d\n", current_character, st);
}


AT_COMMAND_DATA dataStructure = {0};

void printDataStructure()
{
    printf("start of ds:\n");
    for (uint32_t i = 0; i < AT_COMMAND_MAX_LINES; ++i)
    {
        printf("%s", dataStructure.data[i]);
    }
    printf("\nend of ds.");
}
void resetDataStructure()
{
    dataStructure = (AT_COMMAND_DATA){0};
}
void initializeDataStructure()
{
    resetDataStructure();
    dataStructure.line_count=0;
    dataStructure.line_size=0;
}
void addCharToDataStructure(uint8_t current_char)
{
    dataStructure.data[dataStructure.line_count][dataStructure.line_size-1] = current_char;
}
void newlineInDataStructure()
{
    dataStructure.line_count++;
    dataStructure.line_size=0;
}
void lineEndInDataStructure()
{
    dataStructure.data[dataStructure.line_count][dataStructure.line_size] = '\0';
}


STATE_MACHINE_RETURN_VALUE at_command_parse(uint8_t current_character)
{
    static uint32_t state = 1;
    printState(current_character, state);

    if (state==1)
        initializeDataStructure();
    dataStructure.line_size++;
    addCharToDataStructure(current_character);
    switch (state)
    {
        case 1:
        {
            if (current_character == CR)  // 13
            {
                state = 2;
            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 2:
        {
            if (current_character == LF)  // 10
            {
                state = 3;
                lineEndInDataStructure();
                newlineInDataStructure();
            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 3:
        {
            if (current_character == 'O')
            {
                state = 4;

            }
            else if (current_character == 'E')
            {
                state = 14;

            }
            else if (current_character == '+')
            {
                state = 24;
            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 4:
        {
            if (current_character == 'K')
            {
                state = 5;

            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 5:
        {
            if (current_character == CR)
            {
                state = 6;

            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 6:
        {
            if (current_character == LF)
            {
                state = 1;
                lineEndInDataStructure();
                printDataStructure();
                return STATE_MACHINE_READY_OK;
            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 14:
        {
            if (current_character == 'R')
            {
                state = 15;

            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 15:
        {
            if (current_character == 'R')
            {
                state = 16;

            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 16:
        {
            if (current_character == 'O')
            {
                state = 17;

            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 17:
        {
            if (current_character == 'R')
            {
                state = 18;

            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 18:
        {
            if (current_character == CR)
            {
                state = 19;

            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 19:
        {
            if (current_character == LF)
            {
                state = 1;
                lineEndInDataStructure();
                printDataStructure();
                return STATE_MACHINE_READY_OK;
            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 24:  // character processing
        {
            if (current_character >= 32 && current_character <= 126)
            {
                state = 24;
            }
            else if (current_character == CR)
            {
                state = 25;
            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 25:
        {
            if (current_character == LF)
            {
                state = 26;

            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 26:
        {
            if (current_character == CR)
            {
                state = 27;

            }
            else if (current_character == '+')
            {
                state = 24;
                lineEndInDataStructure();
                newlineInDataStructure();
            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 27:
        {
            if (current_character == LF)
            {
                state = 28;

            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 28:
        {
            if (current_character == 'O')
            {
                state = 4;
                lineEndInDataStructure();
                newlineInDataStructure();
            }
            else if (current_character == 'E')
            {
                state = 14;
                lineEndInDataStructure();
                newlineInDataStructure();
            }
            else
            {
                state = 1;
                return STATE_MACHINE_READY_WITH_ERROR;;
            }
            break;
        }
        case 9999:
        {
            state = 1;
            return STATE_MACHINE_READY_OK;
        }
        default:
            return STATE_MACHINE_NOT_READY;
    }

    return STATE_MACHINE_NOT_READY;
}