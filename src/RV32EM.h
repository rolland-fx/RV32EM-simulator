//
// Created by alexa on 2020-06-01.
//

#ifndef RV32EM_SIMULATOR_RV32EM_H
#define RV32EM_SIMULATOR_RV32EM_H

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
    uint32_t imm_31_12;   //20 bits
    uint8_t rd;         //5 bits
    uint8_t opcode;     //7 bits
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
 * Decode l'instruction reçu, alloue de l'espace mémoire pour la structure reliée à ce type d'instruction et retourne
 * le type d'linstruction
 * @param instruction
 * @param return_struct
 * @return type de la structure contenu par le void* return_struct
 */
type_t decoder_instruction(uint32_t instruction, void* return_struct);

/**
 * Decode l'instruction passé en paramètre et place les information de celle-ci dans ptr_struct
 * @param instruction
 * @param ptr_struct
 */
void decoder_type_R(uint32_t instruction, struct_R* ptr_struct);

/**
 * Decode l'instruction passé en paramètre et place les information de celle-ci dans ptr_struct
 * @param instruction
 * @param ptr_struct
 */
void decoder_type_I(uint32_t instruction, struct_I* ptr_struct);

/**
 * Decode l'instruction passé en paramètre et place les information de celle-ci dans ptr_struct
 * @param instruction
 * @param ptr_struct
 */
void decoder_type_S(uint32_t instruction, struct_S* ptr_struct);

/**
 * Decode l'instruction passé en paramètre et place les information de celle-ci dans ptr_struct
 * @param instruction
 * @param ptr_struct
 */
void decoder_type_B(uint32_t instruction, struct_B* ptr_struct);

/**
 * Decode l'instruction passé en paramètre et place les information de celle-ci dans ptr_struct
 * @param instruction
 * @param ptr_struct
 */
void decoder_type_U(uint32_t instruction, struct_U* ptr_struct);

/**
 * Decode l'instruction passé en paramètre et place les information de celle-ci dans ptr_struct
 * @param instruction
 * @param ptr_struct
 */
void decoder_type_J(uint32_t instruction, struct_J* ptr_struct);

#endif //RV32EM_SIMULATOR_RV32EM_H
