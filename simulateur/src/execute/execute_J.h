//
// Created by alexa on 2020-06-11.
//

#ifndef RV32EM_SIMULATOR_EXECUTER_J_H
#define RV32EM_SIMULATOR_EXECUTER_J_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>



#include "../decoder.h"
#include "../memory.h"

#define JAL_OPCODE (0x6f)

/**
 * Execute the J type instruction contain by the struct ptr_struct
 * @param ptr_struct
 * @return non-zero if error
 */
uint8_t execute_type_J(struct_J* ptr_struct);

#endif //RV32EM_SIMULATOR_EXECUTER_J_H
