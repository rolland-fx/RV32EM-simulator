//
// Created by alexa on 2020-06-11.
//


#include "execute_J.h"

uint8_t execute_type_J_JAL(struct_J* ptr_struct){
    uint8_t retVal = 0;
    int32_t imm = ((ptr_struct->imm_20) << 19 & 0x80000) | ((ptr_struct->imm_19_12 << 11) & 0x7f800) |
                     ((ptr_struct->imm_11 << 10) & 0x00400) | ((ptr_struct->imm_10_1 << 0) & 0x003ff);

    imm = imm << 12;
    imm = imm >> 12


    if(ptr_struct->rd < 16) {
        if(ptr_struct->rd != 0)
            Register[ptr_struct->rd] = PC + 4;
        PC += ((imm << 1) & 0xffffe);
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_J(struct_J* ptr_struct){
    uint8_t retVal = 0;

    switch(ptr_struct->opcode){
        case JAL_OPCODE:
            retVal = execute_type_J_JAL(ptr_struct);
            break;
        default:
            retVal = 1;
            break;
    }

    return retVal;
}