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

extern uint32_t Register[REGISTER_NUMBER];
char NextInstructionExist;

char MemoryAdressString[10];
char *ptr;
uint32_t MemoryAdress;
uint8_t MemoryCaseToShow;

char CodeRun(void);
void MemoryChoice(void);
char RunNextInstruction(void);
char ManageRegisterPC(char NextInstructionExist_PC);

#endif //RV32EM_SIMULATOR_MANAGER_H
