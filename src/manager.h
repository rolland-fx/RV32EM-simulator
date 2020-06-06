//
// Created by rolla on 2020-06-05.
//

#ifndef RV32EM_SIMULATOR_MANAGER_H
#define RV32EM_SIMULATOR_MANAGER_H
#include <stdint.h>
#include <stdio.h>
#include "memory.h"

extern uint32_t Register[REGISTER_NUMBER];

char RunNextInstruction(void);
char ManageRegisterPC(char NextInstructionExist);

#endif //RV32EM_SIMULATOR_MANAGER_H
