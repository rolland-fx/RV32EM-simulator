//
// Created by rolla on 2020-06-03.
//
#include "RV32EM.h"

char executer_type_U(uint32_t instruction, struct_U* ptr_struct) {
    char decode_return;
    switch (ptr_struct->opcode) {
        case 0x17 : //LUI
            Register[ptr_struct->rd] = ((ptr_struct->imm << 12) | 0b000000000000);
            decode_return = 1;
            break;
        case 0x37: //AUIPC
            Register[ptr_struct->rd] = (((ptr_struct->imm << 12) | 0b000000000000) + Register[PC]);
            decode_return = 2;
            break;
        default :
            decode_return = 0;
            break;
    }
}
