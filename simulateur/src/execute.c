//
// Created by rolla on 2020-06-03.
//
#include "execute.h"

uint8_t execute_instruction(void* ptr_struct, const type_t* instruction_type){
    uint8_t retVal = 0;

    switch (*instruction_type){
        case R_type:
            retVal = execute_type_R((struct_R*) ptr_struct);
            break;
        case I_type:
            retVal = execute_type_I((struct_I*) ptr_struct);
            break;
        case S_type:
            retVal = execute_type_S((struct_S*) ptr_struct);
            break;
        case B_type:
            retVal = execute_type_B((struct_B*) ptr_struct);
            break;
        case J_type:
            retVal = execute_type_J((struct_J*) ptr_struct);
            break;
        case U_type:
            retVal = execute_type_U((struct_U*) ptr_struct);
            break;
        default:
            break;
    }

    return retVal;
}