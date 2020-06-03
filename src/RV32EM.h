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

}struct_I;

typedef struct{

}struct_S;

typedef struct{

}struct_B;

typedef struct{

}struct_U;

typedef struct{

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



#endif //RV32EM_SIMULATOR_RV32EM_H
