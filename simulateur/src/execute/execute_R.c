//
// Created by alexa on 2020-06-11.
//

#include "execute_R.h"

uint8_t execute_type_R_ADD(struct_R *ptr_struct) {
    uint8_t return_val = 0;

    if (ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16) {
        if(ptr_struct->rd != 0)
            Register[ptr_struct->rd] = Register[ptr_struct->rs1] + Register[ptr_struct->rs2];
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_SUB(struct_R *ptr_struct) {
    uint8_t return_val = 0;

    if (ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16) {
        if(ptr_struct->rd != 0)
            Register[ptr_struct->rd] = Register[ptr_struct->rs1] - Register[ptr_struct->rs2];
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_SLL(struct_R *ptr_struct) {
    uint8_t return_val = 0;
    uint8_t shift_amount = Register[ptr_struct->rs2] & 0b011111;

    if (ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16) {
        if(ptr_struct->rd != 0)
            Register[ptr_struct->rd] = Register[ptr_struct->rs1] << shift_amount;
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_SRL(struct_R *ptr_struct) {
    uint8_t return_val = 0;
    uint8_t shift_amount = Register[ptr_struct->rs2] & 0b011111;

    if (ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16) {
        if(ptr_struct->rd != 0)
            Register[ptr_struct->rd] = Register[ptr_struct->rs1] >> shift_amount;
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_SRA(struct_R *ptr_struct) {
    uint8_t return_val = 0;
    uint8_t shift_amount = Register[ptr_struct->rs2] & 0b011111;

    if (ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16) {
        if(ptr_struct->rd != 0)
            Register[ptr_struct->rd] = (int32_t)(Register[ptr_struct->rs1]) >> shift_amount;
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_XOR(struct_R *ptr_struct) {
    uint8_t return_val = 0;

    if (ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16) {
        if(ptr_struct->rd != 0)
            Register[ptr_struct->rd] = Register[ptr_struct->rs1] ^ Register[ptr_struct->rs2];
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_OR(struct_R *ptr_struct) {
    uint8_t return_val = 0;

    if (ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16) {
        if(ptr_struct->rd != 0)
            Register[ptr_struct->rd] = Register[ptr_struct->rs1] | Register[ptr_struct->rs2];
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_AND(struct_R *ptr_struct) {
    uint8_t return_val = 0;

    if (ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16) {
        if(ptr_struct->rd != 0)
            Register[ptr_struct->rd] = Register[ptr_struct->rs1] & Register[ptr_struct->rs2];
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_SLT(struct_R *ptr_struct) {
    uint8_t return_val = 0;
    int32_t rs1 = Register[ptr_struct->rs1];
    int32_t rs2 = Register[ptr_struct->rs2];

    if (ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16) {
        if (ptr_struct->rd != 0) {
            if (rs1 < rs2) {
                Register[ptr_struct->rd] = 1;
            } else {
                Register[ptr_struct->rd] = 0;
            }
        }
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_SLTU(struct_R *ptr_struct) {
    uint8_t return_val = 0;

    if (ptr_struct->rd < 16 && ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16) {
        if(ptr_struct->rd != 0) {
            if (Register[ptr_struct->rs1] < Register[ptr_struct->rs2]) {
                Register[ptr_struct->rd] = 1;
            } else {
                Register[ptr_struct->rd] = 0;
            }
        }
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_GENERAL(struct_R *ptr_struct) {
    uint8_t return_val = 0;

    switch (ptr_struct->func3) {
        case ADD_FUNCT3:
            return_val = execute_type_R_ADD(ptr_struct);
            break;
        case SLL_FUNCT3:
            return_val = execute_type_R_SLL(ptr_struct);
            break;
        case SLT_FUNCT3:
            return_val = execute_type_R_SLT(ptr_struct);
            break;
        case SLTU_FUNCT3:
            return_val = execute_type_R_SLTU(ptr_struct);
            break;
        case XOR_FUNCT3:
            return_val = execute_type_R_XOR(ptr_struct);
            break;
        case SRL_FUNCT3:
            return_val = execute_type_R_SRL(ptr_struct);
            break;
        case OR_FUNCT3:
            return_val = execute_type_R_OR(ptr_struct);
            break;
        case AND_FUNCT3:
            return_val = execute_type_R_AND(ptr_struct);
            break;
        default:
            return_val = 1;
            break;
    }

    return return_val;
}

uint8_t execute_type_R_SUBSRA(struct_R *ptr_struct) {
    uint8_t return_val = 0;

    switch (ptr_struct->func3) {
        case SUB_FUNCT3:
            return_val = execute_type_R_SUB(ptr_struct);
            break;
        case SRA_FUNCT3:
            return_val = execute_type_R_SRA(ptr_struct);
            break;
        default:
            return_val = 1;
            break;
    }

    return return_val;
}

uint8_t execute_type_R_MUL(struct_R *ptr_struct) {
    uint8_t retVal = 0;
    uint32_t multiplier;
    uint32_t multiplicand;
    uint64_t result;

    if (ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16 && ptr_struct->rd < 16) {
        if(ptr_struct->rd != 0) {
            multiplier = (uint32_t) (Register[ptr_struct->rs2]);
            multiplicand = (uint32_t) (Register[ptr_struct->rs1]);

            result = multiplier * multiplicand;

            Register[ptr_struct->rd] = (uint32_t) (result & 0x00000000ffffffff);
        }

        PC += 4;
    } else {
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_R_MULH(struct_R *ptr_struct) {
    uint8_t retVal = 0;
    int64_t multiplier;
    int64_t multiplicand;
    int64_t result;

    if (ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16 && ptr_struct->rd < 16) {
        if(ptr_struct->rd != 0) {
            multiplier = (int64_t) (Register[ptr_struct->rs2]);
            if (multiplier & 0x80000000)
                multiplier |= 0xffffffff00000000;
            multiplicand = (int64_t) (Register[ptr_struct->rs1]);
            if (multiplicand & 0x80000000)
                multiplicand |= 0xffffffff00000000;

            result = multiplier * multiplicand;

            Register[ptr_struct->rd] = (uint32_t) ((result & 0xffffffff00000000) >> 32);
        }

        PC += 4;
    } else {
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_R_MULHU(struct_R *ptr_struct) {
    uint8_t retVal = 0;
    uint64_t multiplier;
    uint64_t multiplicand;
    uint64_t result;

    if (ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16 && ptr_struct->rd < 16) {
        if(ptr_struct->rd != 0) {
            multiplier = (uint64_t) (Register[ptr_struct->rs2]);
            multiplicand = (uint64_t) (Register[ptr_struct->rs1]);

            result = multiplier * multiplicand;

            Register[ptr_struct->rd] = (uint32_t) ((result & 0xffffffff00000000) >> 32);
        }

        PC += 4;
    } else {
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_R_MULHSU(struct_R *ptr_struct) {
    uint8_t retVal = 0;
    uint64_t multiplier;
    int64_t multiplicand;
    int64_t result;

    if (ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16 && ptr_struct->rd < 16) {
        if(ptr_struct->rd != 0) {
            multiplier = (uint64_t) (Register[ptr_struct->rs2]);
            multiplicand = (int64_t) (Register[ptr_struct->rs1]);
            if (multiplicand & 0x80000000)
                multiplicand |= 0xffffffff00000000;

            result = multiplier * multiplicand;

            Register[ptr_struct->rd] = (uint32_t) ((result & 0xffffffff00000000) >> 32);

        }
        PC += 4;
    } else {
        retVal = 1;
    }

    return retVal;
}

uint8_t execute_type_R_DIV(struct_R *ptr_struct) {
    uint8_t return_val = 0;
    int32_t dividend;
    int32_t divisor;

    if (ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16 && ptr_struct->rd < 16) {
        if(ptr_struct->rd != 0) {
            dividend = (int32_t) (Register[ptr_struct->rs1]);
            divisor = (int32_t) (Register[ptr_struct->rs2]);

            Register[ptr_struct->rd] = (uint32_t) (dividend / divisor);
        }
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_DIVU(struct_R *ptr_struct) {
    uint8_t return_val = 0;
    uint32_t dividend;
    uint32_t divisor;

    if (ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16 && ptr_struct->rd < 16) {
        if(ptr_struct->rd != 0) {
            dividend = (uint32_t) (Register[ptr_struct->rs1]);
            divisor = (uint32_t) (Register[ptr_struct->rs2]);

            Register[ptr_struct->rd] = (uint32_t) (dividend / divisor);
        }
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_REM(struct_R *ptr_struct) {
    uint8_t return_val = 0;
    int32_t dividend;
    int32_t divisor;
    int32_t result;

    if (ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16 && ptr_struct->rd < 16) {
        if(ptr_struct->rd != 0) {
            dividend = (int32_t) (Register[ptr_struct->rs1]);
            divisor = (int32_t) (Register[ptr_struct->rs2]);

            result = (int32_t) (dividend % divisor);

            if (((dividend >> 31) & 1) == 1){
                Register[ptr_struct->rd] = 0x80000000 | ((uint32_t) result);
            } else {
                Register[ptr_struct->rd] = 0x7fffffff & ((uint32_t) result);
            }
        }
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_REMU(struct_R *ptr_struct) {
    uint8_t return_val = 0;
    uint32_t dividend;
    uint32_t divisor;

    if (ptr_struct->rs1 < 16 && ptr_struct->rs2 < 16 && ptr_struct->rd < 16) {
        if(ptr_struct->rd != 0) {
            dividend = (uint32_t) (Register[ptr_struct->rs1]);
            divisor = (uint32_t) (Register[ptr_struct->rs2]);

            Register[ptr_struct->rd] = (uint32_t) (dividend % divisor);
        }
        PC = PC + 4;
    } else {
        return_val = 1;
    }

    return return_val;
}

uint8_t execute_type_R_MULDIV(struct_R *ptr_struct) {
    uint8_t return_val = 0;

    switch (ptr_struct->func3) {
        case MUL_FUNCT3: //MUL
            return_val = execute_type_R_MUL(ptr_struct);
            break;
        case MULH_FUNCT3: //MULH
            return_val = execute_type_R_MULH(ptr_struct);
            break;
        case MULHSU_FUNCT3: //MULHSU
            return_val = execute_type_R_MULHSU(ptr_struct);
            break;
        case MULHU_FUNCT3: //MULHU
            return_val = execute_type_R_MULHU(ptr_struct);
            break;
        case DIV_FUNCT3: //DIV
            return_val = execute_type_R_DIV(ptr_struct);
            break;
        case DIVU_FUNCT3: //DIVU
            return_val = execute_type_R_DIVU(ptr_struct);
            break;
        case REM_FUNCT3: //REM
            return_val = execute_type_R_REM(ptr_struct);
            break;
        case REMU_FUNCT3: //REMU
            return_val = execute_type_R_REMU(ptr_struct);
            break;
        default:
            return_val = 1;
            break;
    }

    return return_val;
}

uint8_t execute_type_R(struct_R *ptr_struct) {
    uint8_t return_val = 0;

    switch (ptr_struct->funct7) {
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


