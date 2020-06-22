//
// Created by alexa on 2020-06-11.
//

#ifndef RV32EM_SIMULATOR_EXECUTER_I_H
#define RV32EM_SIMULATOR_EXECUTER_I_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "../decoder.h"
#include "../memory.h"

#define LOAD_OPCODE (0x03)
#define JALR_OPCODE (0x67)
#define FENCE_OPCODE (0x0F)
#define ARMT_OPCODE (0x13)
#define ECALL_OPCODE (0x73)

#define ADDI_FUNCT3 (0x00)
#define SLLI_FUNCT3 (0x01)
#define SLTI_FUNCT3 (0x02)
#define SLTIU_FUNCT3 (0x03)
#define XORI_FUNCT3 (0x04)
#define SRLI_FUNCT3 (0x05)
#define ORI_FUNCT3 (0x06)
#define ANDI_FUNCT3 (0x07)

#define LB_FUNCT3 (0x00)
#define LH_FUNCT3 (0x01)
#define LW_FUNCT3 (0x02)
#define LBU_FUNCT3 (0x04)
#define LHU_FUNCT3 (0x05)


/**
 *
 * @param ptr_struct
 */
uint8_t execute_type_I(struct_I *ptr_struct);

#endif //RV32EM_SIMULATOR_EXECUTER_I_H
