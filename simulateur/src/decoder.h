//
// Created by alexa on 2020-06-11.
//

#ifndef RV32EM_SIMULATOR_DECODER_H
#define RV32EM_SIMULATOR_DECODER_H
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef enum type_t {R_type, I_type, S_type, B_type, U_type, J_type} type_t;

typedef struct{
    uint8_t funct7; //7 bits
    uint8_t rs2;    //5 bits
    uint8_t rs1;    //5 bits
    uint8_t func3;  //3 bits
    uint8_t rd;     //5 bits
    uint8_t opcode; //7 bits
}struct_R;

typedef struct{
    uint16_t imm_11_0;   //12 bits
    uint8_t rs1;        //5 bits
    uint8_t func3;      //3 bits
    uint8_t rd;         //5 bits
    uint8_t opcode;     //7 bits
}struct_I;

typedef struct{
    uint8_t imm_11_5;   //7 bits
    uint8_t rs2;        //5 bits
    uint8_t rs1;        //5 bits
    uint8_t func3;      //3 bits
    uint8_t imm_4_0;    //5 bits
    uint8_t opcode;     //7 bits
}struct_S;

typedef struct{
    uint8_t imm_12  ;   //1 bits
    uint8_t imm_10_5;   //6 bits
    uint8_t rs2;        //5 bits
    uint8_t rs1;        //5 bits
    uint8_t func3;      //3 bits
    uint8_t imm_4_1;    //4 bits
    uint8_t imm_11;     //1 bits
    uint8_t opcode;     //7 bits
}struct_B;

typedef struct{
    uint32_t imm;   //20 bits
    uint8_t rd;     //5 bits
    uint8_t opcode; //7 bits (LUI : 0x17 / AUIPC : 0x37)

}struct_U;

typedef struct{
    uint8_t imm_20;     //1 bits
    uint16_t imm_10_1;   //10 bits
    uint8_t imm_11;     //1 bits
    uint8_t imm_19_12;  //8 bits
    uint8_t rd;         //5 bits
    uint8_t opcode;     //7 bits
}struct_J;

/**
 * Decode the instructions, then alloc the memory needed for the struct of this type of
 * instruction
 * @param instruction : hexa format extracted from memory
 * @param return_struct : struct to fill with decoded instruction
 * @return type of struct of the void* return_struct
 */
void* decoder_instruction(uint32_t instruction, type_t* instruction_type);

/**
 * Decode the specific type R instruction and fill the struct with informations
 * @param instruction : hexa format extracted from memory
 * @param ptr_struct : struct to fill with decoded instruction
 */
void decoder_type_R(uint32_t instruction, struct_R* ptr_struct);

/**
 * Decode the specific type I instruction and fill the struct with informations
 * @param instruction : hexa format extracted from memory
 * @param ptr_struct : struct to fill with decoded instruction
 */
void decoder_type_I(uint32_t instruction, struct_I* ptr_struct);

/**
 * Decode the specific type S instruction and fill the struct with informations
 * @param instruction : hexa format extracted from memory
 * @param ptr_struct : struct to fill with decoded instruction
 */
void decoder_type_S(uint32_t instruction, struct_S* ptr_struct);

/**
 * Decode the specific type B instruction and fill the struct with informations
 * @param instruction : hexa format extracted from memory
 * @param ptr_struct : struct to fill with decoded instruction
 */
void decoder_type_B(uint32_t instruction, struct_B* ptr_struct);

/**
 * Decode the specific type U instruction and fill the struct with informations
 * @param instruction : hexa format extracted from memory
 * @param ptr_struct : struct to fill with decoded instruction
 */
void decoder_type_U(uint32_t instruction, struct_U* ptr_struct);

/**
 * Decode the specific type J instruction and fill the struct with informations
 * @param instruction : hexa format extracted from memory
 * @param ptr_struct : struct to fill with decoded instruction
 */
void decoder_type_J(uint32_t instruction, struct_J* ptr_struct);


#endif //RV32EM_SIMULATOR_DECODER_H
