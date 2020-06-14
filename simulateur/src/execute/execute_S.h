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

uint8_t execute_type_S(struct_S* ptr_struct);

#endif //RV32EM_SIMULATOR_EXECUTER_S_H
