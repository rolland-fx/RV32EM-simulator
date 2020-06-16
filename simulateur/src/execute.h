//
// Created by alexa on 2020-06-11.
//

#ifndef RV32EM_SIMULATOR_EXECUTER_H
#define RV32EM_SIMULATOR_EXECUTER_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "execute/execute_R.h"
#include "execute/execute_I.h"
#include "execute/execute_S.h"
#include "execute/execute_B.h"
#include "execute/execute_U.h"
#include "execute/execute_J.h"


#include "decoder.h"
#include "memory.h"

uint8_t execute_instruction(void* ptr_struct, const type_t instruction_type);

#endif //RV32EM_SIMULATOR_EXECUTER_H
