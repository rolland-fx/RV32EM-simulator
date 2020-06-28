//
// Created by alexa on 2020-06-11.
//

#include "execute_B.h"

uint8_t execute_type_B_BEQ(struct_B* ptr_struct){
    uint8_t retVal = 0;
    uint32_t imm = (ptr_struct->imm_4_1 << 1u) | (ptr_struct->imm_10_5 << 5u)
            | (ptr_struct->imm_11 << 11u) | (ptr_struct->imm_12 << 12u);

    if (imm & 0x00001000u){
        imm = 0xFFFFE000u | imm;
    }
    else{
        imm = 0x00000000u | imm;
    }

    if(ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16){
        if(Register[ptr_struct->rs1] == Register[ptr_struct->rs2]){
            PC += imm;
        }
        else{
            PC += 4;
        }
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_B_BNE(struct_B* ptr_struct){
    uint8_t retVal = 0;
    uint32_t imm = (ptr_struct->imm_4_1 << 1u) | (ptr_struct->imm_10_5 << 5u)
                   | (ptr_struct->imm_11 << 11u) | (ptr_struct->imm_12 << 12u);

    if (imm & 0x00001000u){
        imm = 0xFFFFE000u | imm;
    }
    else{
        imm = 0x00000000u | imm;
    }

    if(ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16){
        if(Register[ptr_struct->rs1] != Register[ptr_struct->rs2]){
            PC += imm;
        } else{
            PC += 4;
        }
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_B_BLT(struct_B* ptr_struct){
    uint8_t retVal = 0;
    uint32_t imm = (ptr_struct->imm_4_1 << 1u) | (ptr_struct->imm_10_5 << 5u)
                   | (ptr_struct->imm_11 << 11u) | (ptr_struct->imm_12 << 12u);

    if (imm & 0x00001000u){
        imm = 0xFFFFE000u | imm;
    }
    else{
        imm = 0x00000000u | imm;
    }

    if(ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16){
        if((int32_t)Register[ptr_struct->rs1] < (int32_t)Register[ptr_struct->rs2]){
            PC += imm;
        }
        else{
            PC += 4;
        }
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_B_BGE(struct_B* ptr_struct){
    uint8_t retVal = 0;
    uint32_t imm = (ptr_struct->imm_4_1 << 1u) | (ptr_struct->imm_10_5 << 5u)
                   | (ptr_struct->imm_11 << 11u) | (ptr_struct->imm_12 << 12u);

    if (imm & 0x00001000u){
        imm = 0xFFFFE000u | imm;
    }
    else{
        imm = 0x00000000u | imm;
    }

    if(ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16){
        if((int32_t)Register[ptr_struct->rs1] >= (int32_t)Register[ptr_struct->rs2]){
            PC += imm;
        }
        else{
            PC += 4;
        }
    }
    else{
        retVal = 1;
    }
    return retVal;
}

uint8_t execute_type_B_BLTU(struct_B* ptr_struct){
    uint8_t retVal = 0;
    uint32_t imm = (ptr_struct->imm_4_1 << 1u) | (ptr_struct->imm_10_5 << 5u)
                   | (ptr_struct->imm_11 << 11u) | (ptr_struct->imm_12 << 12u);

    if (imm & 0x00001000u){
        imm = 0xFFFFE000u | imm;
    }
    else{
        imm = 0x00000000u | imm;
    }

    if(ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16){
        if((uint32_t)abs(Register[ptr_struct->rs1]) < (uint32_t)abs(Register[ptr_struct->rs2])){
            PC += imm;
        }
        else{
            PC += 4;
        }
    }
    else {
        retVal = 1;
    }
    return retVal;
}

uint8_t execute_type_B_BGEU(struct_B* ptr_struct){
    uint8_t retVal = 0;
    uint32_t imm = (ptr_struct->imm_4_1 << 1u) | (ptr_struct->imm_10_5 << 5u)
                   | (ptr_struct->imm_11 << 11u) | (ptr_struct->imm_12 << 12u);

    if (imm & 0x00001000u){
        imm = 0xFFFFE000u | imm;
    }
    else{
        imm = 0x00000000u | imm;
    }

    if(ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16){
        if((uint32_t)abs(Register[ptr_struct->rs1]) >= (uint32_t)abs(Register[ptr_struct->rs2])){
            PC += imm;
        }
        else{
            PC += 4;
        }
    }
    else {
        retVal = 1;
    }
    return retVal;
}


uint8_t execute_type_B(struct_B* ptr_struct) {
    uint8_t return_val = 0;

    switch(ptr_struct->func3){
        case BEQ_FUNCT3: //BEQ
            return_val = execute_type_B_BEQ(ptr_struct);
            break;
        case BNE_FUNCT3: //BNE
            return_val = execute_type_B_BNE(ptr_struct);
            break;
        case BLT_FUNCT3: //BLT
            return_val = execute_type_B_BLT(ptr_struct);
            break;
        case BGE_FUNCT3: //BGE
            return_val = execute_type_B_BGE(ptr_struct);
            break;
        case BLTU_FUNCT3: //BLTU
            return_val = execute_type_B_BLTU(ptr_struct);
            break;
        case BGEU_FUNCT3: //BGEU
            return_val = execute_type_B_BGEU(ptr_struct);
            break;
        default:
            return_val = 1;
            break;
    }

    return return_val;
}