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
/**
 * Will call the proper executer for the decoded instructions
 * And will pass the pointer to the structure that contain all the informations needed
 * @param instruction_type : type of instruction decoded
 * @param ptr_struct : pointer to the structure corresponding to the decoded instruction type
 * @return : 0 if instruction executed properly, 1 if not
 */
uint8_t execute_instruction(void* ptr_struct, const type_t instruction_type);

#endif //RV32EM_SIMULATOR_EXECUTER_H
