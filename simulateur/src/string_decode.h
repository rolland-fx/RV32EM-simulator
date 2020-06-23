//
// Created by jeanp on 2020-06-22.
//

#ifndef RV32EM_SIMULATOR_STRING_DECODE_H
#define RV32EM_SIMULATOR_STRING_DECODE_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "execute.h"

void create_string_instruction(type_t instruction_type, void* ptr_struct, uint32_t instruction, char* buffer);

#endif //RV32EM_SIMULATOR_STRING_DECODE_H
