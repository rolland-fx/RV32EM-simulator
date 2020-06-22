//
// Created by alexa on 2020-06-11.
//

#include "execute_S.h"

uint8_t execute_type_S(struct_S* ptr_struct)
{
    uint8_t return_val = 0;
    uint32_t value;
    uint32_t address;
    uint8_t bit7;
    uint8_t bit15;
    uint8_t bit11;
    uint32_t offset = (uint32_t)((ptr_struct->imm_11_5 << 6) + ptr_struct->imm_4_0);
    bit11 = offset & 0x00000800u;
    if (bit11 == '1')
    {
        offset = 0xFFFFF000u | offset;
    }
    else
    {
        offset = 0x00000000u | offset;
    }
    address = Register[ptr_struct->rs1] + offset;
    value = Register[ptr_struct->rs2];
    switch(ptr_struct->func3){
        case STORE_8bits: //SB
            bit7 = value & 0x10u;
            if (bit7 =='1')
            {
                //userMemory[address] = 0xFFFFFF00u | value;
                user_memory_save_byte(address, value);
            }
            else
            {
                //userMemory[address] = 0x00000000u | value;
                user_memory_save_byte(address, 0x00000000u | value);
            }
            PC += 4;
        break;
        case STORE_16bits:
            bit15 = value & 0x1000u;
            if (bit15 =='1')
            {
                //userMemory[address] = 0xFFFF0000u | value;
                user_memory_save_half_word(address, 0xFFFF0000u | value);
            }
            else
            {
                //userMemory[address] = 0x00000000u | value;
                user_memory_save_half_word(address, 0x00000000u | value);
            }
            PC += 4;
        break;
        case STORE_32bits:
            //userMemory[address] = value;
            user_memory_save_word(address, value);
            PC += 4;
        break;
        default:
        return_val = 1;
        break;
    }
    return return_val;
}