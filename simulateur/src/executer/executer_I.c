//
// Created by alexa on 2020-06-11.
//

#include "executer_I.h"

void executer_type_I(uint32_t instruction, struct_I* ptr_struct) {
    switch (ptr_struct->opcode) {
        case 0x03:  //LB,LH,LW,LBU,LHU
            executer_type_I_LOAD(ptr_struct);
            break;
        case 0x0F:  //FENCE
            break;
        case 0x13:  //ADDI,SLTI,SLTIU,XORI,ORI,ANDI,SLLI,SRLI,SRAI
            break;
        case 0x67:  //JALR
            break;
        case 0x73:  //ECALL
            break;
        default :
            break;
    }
}

void executer_type_I_LOAD(struct_I* ptr_struct){
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
            Register[ptr_struct->rd] = *(uint32_t*)((uint32_t)ptr_struct->rs1 + (uint32_t)ptr_struct->imm_11_0);
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