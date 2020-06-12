//
// Created by alexa on 2020-06-11.
//

#ifndef RV32EM_SIMULATOR_EXECUTER_B_H
#define RV32EM_SIMULATOR_EXECUTER_B_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "../decoder.h"
#include "../memory.h"

#define BEQ_FUNCT3 (0x00)
#define BNE_FUNCT3 (0x01)
#define BLT_FUNCT3 (0x04)
#define BGE_FUNCT3 (0x05)
#define BLTU_FUNCT3 (0x06)
#define BGEU_FUNCT3 (0x07)

/**
 * Execute the B type instruction contain by the struct ptr_struct
 * @param ptr_struct
 * @return non-zero if error
 */
uint8_t execute_type_B(struct_B* ptr_struct);

#endif //RV32EM_SIMULATOR_EXECUTER_B_H
