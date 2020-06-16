//
// Created by jeanp on 2020-06-03.
//

#include "decoder.h"

/**
 * Decodes the instruction of type R and puts every parts inside a structure
 * @param instruction
 * @param ptr_struct
 */
void decoder_type_R(uint32_t instruction, struct_R* ptr_struct){

    ptr_struct->opcode      =   (instruction & 0x0000007Fu);
    ptr_struct->rd          =   (instruction & 0x00000F80u) >> 7u;
    ptr_struct->func3       =   (instruction & 0x00007000u) >> 12u;
    ptr_struct->rs1         =   (instruction & 0x000F8000u) >> 15u;
    ptr_struct->rs2         =   (instruction & 0x01F00000u) >> 20u;
    ptr_struct->funct7      =   (instruction & 0xFE000000u) >> 25u;
}

/**
 * Decodes the instruction of type I and puts every parts inside a structure
 * @param instruction
 * @param ptr_struct
 */
void decoder_type_I(uint32_t instruction, struct_I* ptr_struct){

    ptr_struct->opcode      =   (instruction & 0x0000007Fu);
    ptr_struct->rd          =   (instruction & 0x00000F80u) >> 07u;
    ptr_struct->func3       =   (instruction & 0x00007000u) >> 12u;
    ptr_struct->rs1         =   (instruction & 0x000F8000u) >> 15u;
    ptr_struct->imm_11_0    =   (instruction & 0xFFF00000u) >> 20u;
}
/**
 * Decodes the instruction of type S and puts every parts inside a structure
 * @param instruction
 * @param ptr_struct
 */
void decoder_type_S(uint32_t instruction, struct_S* ptr_struct){

    ptr_struct->opcode      =   (instruction & 0x0000007Fu);
    ptr_struct->imm_4_0     =   (instruction & 0x00000F80u) >> 07u;
    ptr_struct->func3       =   (instruction & 0x00007000u) >> 12u;
    ptr_struct->rs1         =   (instruction & 0x000F8000u) >> 15u;
    ptr_struct->rs2         =   (instruction & 0x01F00000u) >> 20u;
    ptr_struct->imm_11_5    =   (instruction & 0xFE000000u) >> 25u;
}

/**
 * Decodes the instruction of type B and puts every parts inside a structure
 * @param instruction
 * @param ptr_struct
 */
void decoder_type_B(uint32_t instruction, struct_B* ptr_struct){

    ptr_struct->opcode      =   (instruction & 0x0000007Fu);
    ptr_struct->imm_11      =   (instruction & 0x00000080u) >> 7u;
    ptr_struct->imm_4_1     =   (instruction & 0x00000F00u) >> 8u;
    ptr_struct->func3       =   (instruction & 0x00007000u) >> 12u;
    ptr_struct->rs1         =   (instruction & 0x000F8000u) >> 15u;
    ptr_struct->rs2         =   (instruction & 0x01F00000u) >> 20u;
    ptr_struct->imm_10_5    =   (instruction & 0x7E000000u) >> 25u;
    ptr_struct->imm_12      =   (instruction & 0x80000000u) >> 31u;
}

/**
 * Decodes the instruction of type J and puts every parts inside a structure
 * @param instruction
 * @param ptr_struct
 */
void decoder_type_J(uint32_t instruction, struct_J* ptr_struct){

    ptr_struct->opcode      =   (instruction & 0x0000007Fu);
    ptr_struct->rd          =   (instruction & 0x00000F80u) >> 07u;
    ptr_struct->imm_19_12   =   (instruction & 0x000FF000u) >> 12u;
    ptr_struct->imm_11      =   (instruction & 0x00100000u) >> 20u;
    ptr_struct->imm_10_1    =   (instruction & 0x7FE00000u) >> 21u;
    ptr_struct->imm_20      =   (instruction & 0x80000000u) >> 31u;
}

void decoder_type_U(uint32_t instruction, struct_U* ptr_struct) {
    ptr_struct->opcode      =   (instruction & 0x0000007Fu);
    ptr_struct->rd          =   (instruction & 0x00000F80u) >> 07u;
    ptr_struct->imm         =   (instruction & 0xFFFFF000u) >> 12u;
}


/**
 * *** À COMPLÉTER ***
 * Can decode any type of instruction puts the parts of the instruction inside a structre.
 * Return the type of the instruction decoded
 * @param instruction
 * @param return_struct
 * @return
 */
void* decoder_instruction(uint32_t instruction, type_t* instruction_type){

    uint8_t opcode = (instruction & 0x7Fu);
    void* retVal = NULL;
    switch (opcode) {
        case 0x33: *instruction_type = R_type; break;
        case 0x03:
        case 0x0F:
        case 0x13:
        case 0x67:
        case 0x73: *instruction_type = I_type; break;
        case 0x23: *instruction_type = S_type; break;
        case 0x63: *instruction_type = B_type; break;
        case 0x17:
        case 0x37: *instruction_type = U_type; break;
        case 0x6F: *instruction_type = J_type; break;
        default:    break;
    }
    switch (*instruction_type) {
        case R_type:
            retVal = malloc(sizeof(struct_R));
            decoder_type_R(instruction,(struct_R*)(retVal));
            break;
        case I_type:
            retVal = malloc(sizeof(struct_I));
            decoder_type_I(instruction,(struct_I*)(retVal));
            break;
        case S_type:
            retVal = malloc(sizeof(struct_S));
            decoder_type_S(instruction,(struct_S*)(retVal));
            break;
        case B_type:
            retVal = malloc(sizeof(struct_B));
            decoder_type_B(instruction,(struct_B*)(retVal));
            break;
        case U_type:
            retVal = malloc(sizeof(struct_U));
            decoder_type_U(instruction,(struct_U*)(retVal));
            break;
        case J_type:
            retVal = malloc(sizeof(struct_J));
            decoder_type_J(instruction,(struct_J*)(retVal));
            break;
        default:    break;
    }
    return retVal;
}