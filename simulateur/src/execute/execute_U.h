//
// Created by alexa on 2020-06-11.
//

#ifndef RV32EM_SIMULATOR_EXECUTER_U_H
#define RV32EM_SIMULATOR_EXECUTER_U_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "../decoder.h"
#include "../memory.h"

/**
 * Execute une instruction de type U en utilisant les informations stockée dans la structure
 * @param instruction
 * @param ptr_struct
 */
uint8_t execute_type_U(struct_U* ptr_struct);

#endif //RV32EM_SIMULATOR_EXECUTER_U_H
