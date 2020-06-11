//
// Created by alexa on 2020-06-11.
//

#include "execute_I.h"

void execute_type_I_LOAD(struct_I* ptr_struct){
    uint32_t value;
    uint8_t bit7;
    uint16_t bit15;
    switch (ptr_struct->func3){
        case 0x0:   //LB
            value = *(uint32_t*)(((uint32_t)ptr_struct->rs1 + (uint32_t)ptr_struct->imm_11_0) & 0xFFu);
            bit7 = value & 0x10u;
            if (bit7 =='1')
                Register[ptr_struct->rd] = 0xFFFFFF00u | value;
            else
                Register[ptr_struct->rd] = 0x00000000u | value;
            break;
        case 0x1:   //LH
            value = *(uint32_t*)(((uint32_t)ptr_struct->rs1 + (uint32_t)ptr_struct->imm_11_0) & 0xFFFFu);
            bit15 = value & 0x1000u;
            if (bit15 =='1')
                Register[ptr_struct->rd] = 0xFFFF0000u | value;
            else
                Register[ptr_struct->rd] = 0x00000000u | value;
            break;
        case 0x2:   //LW
            Register[ptr_struct->rd] = userMemory[ptr_struct->rs1 + ptr_struct->imm_11_0];
                    //*(uint32_t*)((uint32_t)ptr_struct->rs1 + (uint32_t)ptr_struct->imm_11_0);
            break;
        case 0x4:   //LBU
            value = *(uint32_t*)(((uint32_t)ptr_struct->rs1 + (uint32_t)ptr_struct->imm_11_0) & 0xFFu);
            Register[ptr_struct->rd] = 0x00000000u | value;
            break;
        case 0x5:   //LHU
            value = *(uint32_t*)(((uint32_t)ptr_struct->rs1 + (uint32_t)ptr_struct->imm_11_0) & 0xFFFFu);
            Register[ptr_struct->rd] = 0x00000000u | value;
            break;
    }
}

uint8_t execute_type_I_JALR(struct_I* ptr_struct){
    uint8_t retVal = 0;

    if(ptr_struct->rd < 16) {
        if(ptr_struct->rd != 0)
            Register[ptr_struct->rd] = PC + 4;
        PC += (ptr_struct->imm_11_0 + Register[ptr_struct->rs1]);
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_I_ADDI(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint32_t imm = ptr_struct->imm_11_0;

    if(ptr_struct->imm_11_0 & 0x00000800) {
        imm |= 0xfffff000;
    }

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
        Register[ptr_struct->rd] = Register[ptr_struct->rs1] + imm;
        PC += 4;
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_I_SLTI(struct_I* ptr_struct){
    uint8_t retVal = 0;

    int16_t imm = (ptr_struct->imm_11_0);
    if(imm & 0x00000800){
        imm |= 0xfffff000;
    }

    int32_t rs1 = (Register[ptr_struct->rs1]);

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
        if(Register[ptr_struct->rs1] < imm){
            Register[ptr_struct->rd] = 1;
        }
        else{
            Register[ptr_struct->rd] = 0;
        }
        PC += 4;
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_I_ARMT(struct_I* ptr_struct){
    uint8_t retVal = 0;

    switch(ptr_struct->func3){
        case ADDI_FUNCT3:
            retVal = execute_type_I_ADDI(ptr_struct);
            break;
        case SLTI_FUNCT3:
            retVal = execute_type_I_SLTI(ptr_struct);
            break;
        case SLTIU_FUNCT3:
            break;
        case XORI_FUNCT3:
            break;
        case ORI_FUNCT3:
            break;
        case ANDI_FUNCT3:
            break;
    }

    return retVal;
}

uint8_t execute_type_I(struct_I* ptr_struct) {
    uint8_t retVal = 0;

    switch (ptr_struct->opcode) {
        case LOAD_OPCODE:  //LB,LH,LW,LBU,LHU
            execute_type_I_LOAD(ptr_struct);
            break;
        case FENCE_OPCODE:  //FENCE
            break;
        case ARMT_OPCODE:  //ADDI,SLTI,SLTIU,XORI,ORI,ANDI,SLLI,SRLI,SRAI
            retVal = execute_type_I_ARMT(ptr_struct);
            break;
        case JALR_OPCODE:  //JALR
            retVal = execute_type_I_JALR(ptr_struct);
            break;
        case ECALL_OPCODE:  //ECALL
            break;
        default :
            break;
    }

    return retVal;
}