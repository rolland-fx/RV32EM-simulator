#include "RV32EM.h"

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
