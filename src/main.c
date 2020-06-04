#include "RV32EM.h"

char decoder_type_U(uint32_t instruction, struct_U* ptr_struct) {
    char decode_return;
    switch (instruction & 0x0000007Fu) {
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


int main(int argc, char *argv[] ) {
    char Filename_Buffer[30];
    FILE* HexaSourceFile = fopen(argv[1],"r");
    //AffichageInitial();
    if(HexaSourceFile == NULL)
    {
        //AffichageErreur();
        return -1;
    }
    //MemoryCreation();
    //loadFile(HexaSourceFile);
    //ChoixModeExecution();
    return 0;
}
