//
// Created by alexa on 2020-06-11.
//

#ifndef RV32EM_SIMULATOR_EXECUTER_R_H
#define RV32EM_SIMULATOR_EXECUTER_R_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "../decoder.h"
#include "../memory.h"

#define ADD_FUNCT3 (0x00)
#define SUB_FUNCT3 (0x00)
#define SLL_FUNCT3 (0x01)
#define SLT_FUNCT3 (0x02)
#define SLTU_FUNCT3 (0x03)
#define XOR_FUNCT3 (0x04)
#define SRL_FUNCT3 (0x05)
#define SRA_FUNCT3 (0x05)
#define OR_FUNCT3 (0x06)
#define AND_FUNCT3 (0x07)
#define MUL_FUNCT3 (0x00)
#define MULH_FUNCT3 (0x01)
#define MULHSU_FUNCT3 (0x02)
#define MULHU_FUNCT3 (0x03)
#define DIV_FUNCT3 (0x04)
#define DIVU_FUNCT3 (0x05)
#define REM_FUNCT3 (0x06)
#define REMU_FUNCT3 (0x07)

#define R_GENERAL_FUNCT7 (0x00)
#define SUB_SRA_FUNCT7 (0x20)
#define MUL_DIV_FUNCT7 (0x01)

/**
 * Execute the R type instruction contain by the struct ptr_struct
 * @param ptr_struct
 * @return non-zero if error
 */
uint8_t execute_type_R(struct_R* ptr_struct);

#endif //RV32EM_SIMULATOR_EXECUTER_R_H
