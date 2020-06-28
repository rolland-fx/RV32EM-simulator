//
// Created by alexa on 2020-06-11.
//

#ifndef RV32EM_SIMULATOR_EXECUTER_S_H
#define RV32EM_SIMULATOR_EXECUTER_S_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "../decoder.h"
#include "../memory.h"

#define STORE_8bits (0x0)
#define STORE_16bits (0x1)
#define STORE_32bits (0x2)

/**
 * Execute the S type instruction contain by the struct ptr_struct
 * @param ptr_struct
 * @return non-zero if error
 */
uint8_t execute_type_S(struct_S* ptr_struct);

#endif //RV32EM_SIMULATOR_EXECUTER_S_H
