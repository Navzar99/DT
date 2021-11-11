//
// Created by razva on 30/10/2021.
//

#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include <stdint.h>

#define CR 13
#define LF 10



typedef enum
{
    STATE_MACHINE_NOT_READY,        // 0
    STATE_MACHINE_READY_OK,         // 1
    STATE_MACHINE_READY_WITH_ERROR  // 2
}STATE_MACHINE_RETURN_VALUE;

STATE_MACHINE_RETURN_VALUE at_command_parse(uint8_t current_character);
void printState(uint8_t current_character, uint32_t st);
void printResponse(uint8_t response);
// Data structure

/*
 * If line size is >100, parse without storing the data
 * Step one: check if commands go through right states
 * Step two: set line and lines limits to 1000 and implement storage
 * Step 3: set line limit back to 100 and 128 and add conditions for limits
 *
 * Obs: every line ends with \0 in the data structure
 */

#define AT_COMMAND_MAX_LINES 1000      // max mem for microcontroller (100)
#define AT_COMMAND_MAX_LINE_SIZE 1000  // line size (128)
#define FALSE 0
#define TRUE 1

typedef struct
{
    uint8_t ok; // stores "0" or "1"
    uint8_t data[AT_COMMAND_MAX_LINES][AT_COMMAND_MAX_LINE_SIZE + 1];  // instruction (linile cu +)
    uint32_t line_count;  // string
    uint32_t line_size;
}AT_COMMAND_DATA;



#endif //PROJECT_PARSER_H
