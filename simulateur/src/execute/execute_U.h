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
 * Execute the U type instruction contain by the struct ptr_struct
 * @param ptr_struct
 * @return non-zero if error
 */
uint8_t execute_type_U(struct_U* ptr_struct);

#endif //RV32EM_SIMULATOR_EXECUTER_U_H
