//
// Created by alexa on 2020-06-11.
//

#include "execute_U.h"

uint8_t execute_type_U(struct_U* ptr_struct) {
    uint8_t retVal = 0;
    if(ptr_struct->rd < 16){
        switch (ptr_struct->opcode){
            case LUI_OPCODE: //LUI
                Register[ptr_struct->rd] = ((ptr_struct->imm << 12) | 0b000000000000);
                PC += 4;
            break;
            case AUIPC_OPCODE: //AUIPC
                Register[ptr_struct->rd] = (((ptr_struct->imm << 12) | 0b000000000000) + PC);
                PC += 4;
            break;
            default :
            retVal = 1;
            break;
        }
    }
    else{
        retVal = 1;
    }
    return retVal;
}