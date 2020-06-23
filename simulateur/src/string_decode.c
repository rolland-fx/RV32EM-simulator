//
// Created by jeanp on 2020-06-22.
//

#include "string_decode.h"
void create_string_type_R_general(struct_R* ptr_struct, uint32_t instruction,  char*buffer){
    switch (ptr_struct->func3) {
        case ADD_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [ADD x%d x%d x%d]", instruction, ptr_struct->rd, ptr_struct->rs1,ptr_struct->rs2);
            break;
        case SLL_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SLL x%d x%d x%d]", instruction, ptr_struct->rd, ptr_struct->rs1,ptr_struct->rs2);
            break;
        case SLT_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SLT x%d x%d x%d]", instruction, ptr_struct->rd, ptr_struct->rs1,ptr_struct->rs2);
            break;
        case SLTU_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SLTU x%d x%d x%d]", instruction, ptr_struct->rd, ptr_struct->rs1,ptr_struct->rs2);
            break;
        case XOR_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [XOR x%d x%d x%d]", instruction, ptr_struct->rd, ptr_struct->rs1,ptr_struct->rs2);
            break;
        case SRL_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SRL x%d x%d x%d]", instruction, ptr_struct->rd, ptr_struct->rs1,ptr_struct->rs2);
            break;
        case OR_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [OR x%d x%d x%d]", instruction, ptr_struct->rd, ptr_struct->rs1,ptr_struct->rs2);
            break;
        case AND_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [AND x%d x%d x%d]", instruction, ptr_struct->rd, ptr_struct->rs1,ptr_struct->rs2);
            break;
        default:
            break;
    }
}

void create_string_type_R_SUBSRA(struct_R* ptr_struct, uint32_t instruction,  char*buffer) {
    switch (ptr_struct->func3) {
        case SUB_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SUB x%d x%d x%d]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->rs2);
            break;
        case SRA_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SRA x%d x%d x%d]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->rs2);
            break;
        default:
            break;
    }
}

void create_string_type_R_MULDIV(struct_R* ptr_struct, uint32_t instruction,  char*buffer){
    switch (ptr_struct->func3) {
        case MUL_FUNCT3: //MUL
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [MUL x%d x%d x%d]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->rs2);
            break;
        case MULH_FUNCT3: //MULH
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [MULH x%d x%d x%d]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->rs2);
            break;
        case MULHSU_FUNCT3: //MULHSU
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [MULHSU x%d x%d x%d]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->rs2);
            break;
        case MULHU_FUNCT3: //MULHU
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [MULHU x%d x%d x%d]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->rs2);
            break;
        case DIV_FUNCT3: //DIV
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [DIV x%d x%d x%d]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->rs2);
            break;
        case DIVU_FUNCT3: //DIVU
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [DIVU x%d x%d x%d]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->rs2);
            break;
        case REM_FUNCT3: //REM
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [REM x%d x%d x%d]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->rs2);
            break;
        case REMU_FUNCT3: //REMU
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [REMU x%d x%d x%d]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->rs2);
            break;
        default:

            break;
    }
}

void create_string_type_R(struct_R* ptr_struct, uint32_t instruction,  char*buffer){
    switch (ptr_struct->funct7) {
        case R_GENERAL_FUNCT7:
            create_string_type_R_general(ptr_struct, instruction, buffer);
            break;
        case SUB_SRA_FUNCT7:
            create_string_type_R_SUBSRA(ptr_struct, instruction, buffer);
            break;
        case MUL_DIV_FUNCT7:
            create_string_type_R_MULDIV(ptr_struct, instruction, buffer);
            break;
        default:
            break;
    }
}

void create_string_type_I_LOAD(struct_I* ptr_struct, uint32_t instruction,  char*buffer){
    switch (ptr_struct->func3){
        case 0x0:   //LB
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [LB x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);
            break;
        case 0x1:   //LH
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [LH x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);
            break;
        case 0x2:   //LW
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [LW x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);
            break;
        case 0x4:   //LBU
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [LBU x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);
            break;
        case 0x5:   //LHU
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [LHU x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);
            break;
    }
}

void create_string_type_I_ARMT(struct_I* ptr_struct, uint32_t instruction,  char*buffer){
    switch(ptr_struct->func3){
        case ADDI_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [ADDI x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);  break;
        case SLTI_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SLTI x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0); break;
        case SLTIU_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SLTIU x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);  break;
        case XORI_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [XORI x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);   break;
        case ORI_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [ORI x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);   break;
        case ANDI_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [ANDI x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);  break;
        case SLLI_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SLLI x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);   break;
        case SRLI_FUNCT3:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SRLI x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);   break;
    }
}

void create_string_type_I(struct_I* ptr_struct, uint32_t instruction,  char*buffer){
    switch (ptr_struct->opcode) {
        case LOAD_OPCODE:  //LB,LH,LW,LBU,LHU
            create_string_type_I_LOAD(ptr_struct, instruction, buffer);
            break;
        case FENCE_OPCODE:  //FENCE
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [FENCE]", instruction);
            break;
        case ARMT_OPCODE:  //ADDI,SLTI,SLTIU,XORI,ORI,ANDI,SLLI,SRLI,SRAI
            create_string_type_I_ARMT(ptr_struct, instruction, buffer);
            break;
        case JALR_OPCODE:  //JALR
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [JALR x%d x%d 0x%03X]", instruction, ptr_struct->rd,
                     ptr_struct->rs1, ptr_struct->imm_11_0);
            break;
        case ECALL_OPCODE:  //ECALL
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [ECALL]", instruction);
            break;
        default :
            break;
    }
}

void create_string_type_S(struct_S* ptr_struct, uint32_t instruction,  char*buffer) {

    uint32_t offset = (uint32_t)((ptr_struct->imm_11_5 << 6) + ptr_struct->imm_4_0);

    switch (ptr_struct->func3) {
        case STORE_8bits: //SB
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SB x%d x%d 0x%03X]", instruction, ptr_struct->rs1,
                     ptr_struct->rs2, offset);
            break;
        case STORE_16bits: //SH
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SH x%d x%d 0x%03X]", instruction, ptr_struct->rs1,
                     ptr_struct->rs2, offset);
            break;
        case STORE_32bits: // SW
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [SW x%d x%d 0x%03X]", instruction, ptr_struct->rs1,
                     ptr_struct->rs2, offset);
            break;
        default:

            break;
    }
}

void create_string_type_B(struct_B* ptr_struct, uint32_t instruction,  char*buffer) {
    uint32_t imm = (ptr_struct->imm_4_1 << 1u) | (ptr_struct->imm_10_5 << 5u)
                   | (ptr_struct->imm_11 << 11u) | (ptr_struct->imm_12 << 12u);
    switch(ptr_struct->func3){
        case BEQ_FUNCT3: //BEQ
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [BEQ x%d x%d 0x%03X]", instruction, ptr_struct->rs1,
                     ptr_struct->rs2, imm);
            break;
        case BNE_FUNCT3: //BNE
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [BNE x%d x%d 0x%03X]", instruction, ptr_struct->rs1,
                     ptr_struct->rs2, imm);
            break;
        case BLT_FUNCT3: //BLT
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [BLT x%d x%d 0x%03X]", instruction, ptr_struct->rs1,
                     ptr_struct->rs2, imm);
            break;
        case BGE_FUNCT3: //BGE
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [BGE x%d x%d 0x%03X]", instruction, ptr_struct->rs1,
                     ptr_struct->rs2, imm);
            break;
        case BLTU_FUNCT3: //BLTU
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [BLTU x%d x%d 0x%03X]", instruction, ptr_struct->rs1,
                     ptr_struct->rs2, imm);
            break;
        case BGEU_FUNCT3: //BGEU
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [BGEU x%d x%d 0x%03X]", instruction, ptr_struct->rs1,
                     ptr_struct->rs2, imm);
            break;
        default:
            break;
    }
}

void create_string_type_U(struct_U* ptr_struct, uint32_t instruction, char* buffer) {
    uint32_t imm = (ptr_struct->imm << 12u);
    switch (ptr_struct->opcode)
    {
        case 0x17: //LUI
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [LUI x%d 0x%08X]", instruction, ptr_struct->rd, imm);
            break;
        case 0x37: //AUIPC
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [AUIPC x%d 0x%08X]", instruction, ptr_struct->rd, imm);
            break;
        default :
            break;
    }
}

void create_string_type_J(struct_J* ptr_struct, uint32_t instruction, char* buffer) {
    int32_t imm = (ptr_struct->imm_20 << 19u)  | (ptr_struct->imm_19_12 << 11u)  |
                  (ptr_struct->imm_11 << 10u) | (ptr_struct->imm_10_1 << 0u);

    switch(ptr_struct->opcode){
        case JAL_OPCODE:
            snprintf(buffer, sizeof(buffer), "Instruction : 0x%08X [JAL x%d 0x%08X]", instruction, ptr_struct->rd, imm);
            break;
        default:
            break;
    }
}

void create_string_instruction(type_t instruction_type, void* ptr_struct, uint32_t instruction, char* buffer) {
    switch (instruction_type) {
        case R_type:
            create_string_type_R(ptr_struct, instruction, buffer);
            break;
        case I_type:
            create_string_type_I(ptr_struct, instruction, buffer);
            break;
        case S_type:
            create_string_type_S(ptr_struct, instruction, buffer);
            break;
        case B_type:
            create_string_type_B(ptr_struct, instruction, buffer);
            break;
        case U_type:
            create_string_type_U(ptr_struct, instruction, buffer);
            break;
        case J_type:
            create_string_type_J(ptr_struct, instruction, buffer);
            break;
        default:
            break;
    }
}