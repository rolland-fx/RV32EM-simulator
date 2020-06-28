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

#define buffer_length 1024
/**
 * Create a string (and place it in buffer) with the decoded
 * instructions in readeable format
 * @param buffer : buffer for the string
 * @param instruction : the instruction read the memory
 * @param ptr_struct : pointer to a instruction decoded structure
 * @param instruction_type define the type of instruction decoded
 */
void create_string_instruction(type_t instruction_type, void* ptr_struct, uint32_t instruction, char* buffer);

#endif //RV32EM_SIMULATOR_STRING_DECODE_H
