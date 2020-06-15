//
// Created by alexa on 2020-06-11.
//

#include "execute_I.h"
// A Verifier pour le signe extend ! (Sur tout les Load)
uint8_t execute_type_I_LB(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint32_t offset = (uint32_t)ptr_struct->imm_11_0;

    if (offset & 0x00000800u)
    {
        offset = 0xFFFFF000u | offset;
    }
    else
    {
        offset = 0x00000000u | offset;
    }

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
        Register[ptr_struct->rd] = userMemory[Register[ptr_struct->rs1] + offset] & 0xFFu;
        PC += 4;
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_I_LH(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint32_t offset = (uint32_t)ptr_struct->imm_11_0;
    if (offset & 0x00000800u)
    {
        offset = 0xFFFFF000u | offset;
    }
    else
    {
        offset = 0x00000000u | offset;
    }

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
            Register[ptr_struct->rd] = userMemory[Register[ptr_struct->rs1] + offset] & 0xFFFFu;

        PC += 4;
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_I_LW(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint32_t offset = (uint32_t)ptr_struct->imm_11_0;

    if (offset & 0x00000800u)
    {
        offset = 0xFFFFF000u | offset;
    }
    else
    {
        offset = 0x00000000u | offset;
    }

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
        Register[ptr_struct->rd] = userMemory[Register[ptr_struct->rs1] + offset];
        PC += 4;
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_I_LBU(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint32_t offset = (uint32_t)ptr_struct->imm_11_0;

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
        Register[ptr_struct->rd] = userMemory[Register[ptr_struct->rs1] + offset] & 0xFFu;
        PC += 4;
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_I_LHU(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint32_t offset = (uint32_t)ptr_struct->imm_11_0;

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
        Register[ptr_struct->rd] = userMemory[Register[ptr_struct->rs1] + offset] & 0xFFFFu;
        PC += 4;
    }
    else{
        retVal = 1;
    }

    return retVal;
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

uint8_t execute_type_I_SLTIU(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint32_t imm = (uint32_t)ptr_struct->imm_11_0;

    if (imm & 0x00000800u)
    {
        imm = 0xFFFFF000u | imm;
    }
    else
    {
        imm = 0x00000000u | imm;
    }

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){

        if(imm == 1){
            Register[ptr_struct->rd] = 1;
        }
        else if(imm == 0){
            Register[ptr_struct->rd] = 0;
        }
        else if(Register[ptr_struct->rs1] < imm){
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

uint8_t execute_type_I_XORI(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint32_t imm = (uint32_t)ptr_struct->imm_11_0;

    if (imm & 0x00000800u)
    {
        imm = 0xFFFFF000u | imm;
    }
    else
    {
        imm = 0x00000000u | imm;
    }

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
        if(imm == 0xFFFFFFFFu){
            Register[ptr_struct->rd] = ~Register[ptr_struct->rs1];
        }
        else{
            Register[ptr_struct->rd] = Register[ptr_struct->rs1] ^ imm;
            PC += 4;
        }
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_I_ORI(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint32_t imm = (uint32_t)ptr_struct->imm_11_0;

    if (imm & 0x00000800u)
    {
        imm = 0xFFFFF000u | imm;
    }
    else
    {
        imm = 0x00000000u | imm;
    }

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
        Register[ptr_struct->rd] = Register[ptr_struct->rs1] | imm;
        PC += 4;
    }
    else{
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_I_ANDI(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint32_t imm = (uint32_t)ptr_struct->imm_11_0;

    if (imm & 0x00000800u)
    {
        imm = 0xFFFFF000u | imm;
    }
    else
    {
        imm = 0x00000000u | imm;
    }

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
        Register[ptr_struct->rd] = Register[ptr_struct->rs1] & imm;
        PC += 4;
    }
    else{
        retVal = 1;
    }

    return retVal;
}
// A regarder !
uint8_t execute_type_I_SLLI(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint8_t shamt = ptr_struct->imm_11_0 & 0x01Fu;

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
        Register[ptr_struct->rd] = userMemory[ptr_struct->rs1] << shamt; // Zeros are shifted into the lower bits ???
        PC += 4;
    }
    else{
        retVal = 1;
    }

    return retVal;
}
// A regarder !
uint8_t execute_type_I_SRLI(struct_I* ptr_struct){
    uint8_t retVal = 0;
    uint8_t shamt = ptr_struct->imm_11_0 & 0x01Fu;

    if(ptr_struct->rd < 16 && ptr_struct->rs1 < 16){
        if(ptr_struct->imm_11_0 && 0x400u){
            Register[ptr_struct->rd] = userMemory[ptr_struct->rs1] >> shamt; //  original sign bit is copied into the vacated upper bits ???
        }
        else{
            Register[ptr_struct->rd] = userMemory[ptr_struct->rs1] >> shamt; // Zeros are shifted into the upper bits ???
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
            retVal = execute_type_I_ADDI(ptr_struct);   break;
        case SLTI_FUNCT3:
            retVal = execute_type_I_SLTI(ptr_struct);   break;
        case SLTIU_FUNCT3:
            retVal = execute_type_I_SLTIU(ptr_struct);  break;
        case XORI_FUNCT3:
            retVal = execute_type_I_XORI(ptr_struct);   break;
        case ORI_FUNCT3:
            retVal = execute_type_I_ORI(ptr_struct);    break;
        case ANDI_FUNCT3:
            retVal = execute_type_I_ANDI(ptr_struct);   break;
        case SLLI_FUNCT3:
            retVal = execute_type_I_SLLI(ptr_struct);   break;
        case SRLI_FUNCT3:
            retVal = execute_type_I_SRLI(ptr_struct);   break;
    }

    return retVal;
}

uint8_t execute_type_I_LOAD(struct_I* ptr_struct){
    uint8_t retVal = 0;

    switch (ptr_struct->func3){
        case 0x0:   //LB
            retVal = execute_type_I_LB(ptr_struct);    break;
        case 0x1:   //LH
            retVal = execute_type_I_LH(ptr_struct);    break;
        case 0x2:   //LW
            retVal = execute_type_I_LW(ptr_struct);    break;
        case 0x4:   //LBU
            retVal = execute_type_I_LBU(ptr_struct);   break;
        case 0x5:   //LHU
            retVal = execute_type_I_LHU(ptr_struct);   break;
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