//
// Created by rolla on 2020-06-05.
//

#ifndef RV32EM_SIMULATOR_MANAGER_H
#define RV32EM_SIMULATOR_MANAGER_H
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "memory.h"
#include "interface.h"
#include "decoder.h"
#include "execute.h"
#include "string_decode.h"

extern uint32_t Register[REGISTER_NUMBER];
char NextInstructionExist;

char MemoryAdressString[10];
char *ptr;
uint32_t MemoryAdress;
uint8_t MemoryCaseToShow;

/**
 * Execute the main loop of the simulated RISC-V CPU
 * Process entry by user and calls the steps of execution
 * @return return the number of instructions executed
 */
uint16_t CodeRun(void);
/**
 * Is called to show to the user data of the memory
 * Process address and number of case to show
 * And show it in the command line
 * @return none
 */
void MemoryChoice(void);
/**
 * Get the next instruction in the memory, send it to the decoder
 * and then call the proper executer
 * @param buffer : string to show the decoded instruction to the user
 * @return 0 if end of the program, 1 is there is a next instruction
 */
char RunNextInstruction(char* buffer);

#endif //RV32EM_SIMULATOR_MANAGER_H
