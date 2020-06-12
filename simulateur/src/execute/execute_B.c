//
// Created by alexa on 2020-06-11.
//

#include "execute_B.h"

uint8_t execute_type_B(struct_B* ptr_struct) {
    uint8_t return_val = 0;

    switch(ptr_struct->func3){
        case BEQ_FUNCT3: //BEQ
            break;
        case BNE_FUNCT3: //BNE
            break;
        case BLT_FUNCT3: //BLT
            break;
        case BGE_FUNCT3: //BGE
            break;
        case BLTU_FUNCT3: //BLTU
            break;
        case BGEU_FUNCT3: //BGEU
            break;
        default:
            return_val = 1;
            break;
    }

    return return_val;
}