//
// Created by alexa on 2020-06-11.
//

#include "execute_R.h"

uint8_t execute_type_R_ADD(struct_R* ptr_struct) {
    uint8_t return_val = 0;

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16){
        Register[ptr_struct->rd] = Register[ptr_struct->rs1] + Register[ptr_struct->rs2];
        PC = PC + 4;
    }
    else{
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_SUB(struct_R* ptr_struct) {
    uint8_t return_val = 0;

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16){
        Register[ptr_struct->rd] = Register[ptr_struct->rs2] - Register[ptr_struct->rs1];
        PC = PC + 4;
    }
    else{
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_SLL(struct_R* ptr_struct) {
    uint8_t return_val = 0;

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16){
        Register[ptr_struct->rd] = Register[ptr_struct->rs1] << Register[ptr_struct->rs2];
        PC = PC + 4;
    }
    else{
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_SRL(struct_R* ptr_struct) {
    uint8_t return_val = 0;

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16){
        Register[ptr_struct->rd] = Register[ptr_struct->rs1] >> Register[ptr_struct->rs2];
        PC = PC + 4;
    }
    else{
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_GENERAL(struct_R* ptr_struct) {
    uint8_t return_val = 0;

    switch(ptr_struct->func3){
        case ADD_FUNCT3:
            return_val = execute_type_R_ADD(ptr_struct);
            break;
        case SLL_FUNCT3:
            return_val = execute_type_R_SLL(ptr_struct);
            break;
        case SLT_FUNCT3: //SLT
            break;
        case SLTU_FUNCT3: //SLTU
            break;
        case XOR_FUNCT3: //XOR
            break;
        case SRL_FUNCT3:
            return_val = execute_type_R_SRL(ptr_struct);
            break;
        case OR_FUNCT3: //OR
            break;
        case AND_FUNCT3: //AND
            break;
        default:
            return_val = 1;
            break;
    }

    return return_val;
}

uint8_t execute_type_R_SUBSRA(struct_R* ptr_struct) {
    uint8_t return_val = 0;

    switch(ptr_struct->func3){
        case SUB_FUNCT3:
            return_val = execute_type_R_SUB(ptr_struct);
            break;
        case SRA_FUNCT3: //SRA
            break;
        default:
            return_val = 1;
            break;
    }

    return return_val;
}

uint8_t execute_type_R_MULDIV(struct_R* ptr_struct) {
    uint8_t return_val = 0;

    switch(ptr_struct->func3){
        case MUL_FUNCT3: //MUL
            break;
        case MULH_FUNCT3: //MULH
            break;
        case MULHSU_FUNCT3: //MULHSU
            break;
        case MULHU_FUNCT3: //MULHU
            break;
        case DIV_FUNCT3: //DIV
            break;
        case DIVU_FUNCT3: //DIVU
            break;
        case REM_FUNCT3: //REM
            break;
        case REMU_FUNCT3: //REMU
            break;
        default:
            return_val = 1;
            break;
    }

    return return_val;
}

uint8_t execute_type_R(struct_R* ptr_struct) {
    uint8_t return_val = 0;

    switch(ptr_struct->funct7){
        case R_GENERAL_FUNCT7:
            return_val = execute_type_R_GENERAL(ptr_struct);
            break;
        case SUB_SRA_FUNCT7:
            return_val = execute_type_R_SUBSRA(ptr_struct);
            break;
        case MUL_DIV_FUNCT7:
            return_val = execute_type_R_MULDIV(ptr_struct);
            break;
        default:
            return_val = 1;
            break;
    }

    return return_val;
}


