#include "RV32EM.h"

int main(int argc, char *argv[] ) {
    char FileName[30];
    setbuf(stdout,0);
    InitialPrint();
    if (argv[1] == NULL){
        printf("Entrez le nom du fichier a simuler:\n");
        printf(">");
        scanf("%s", FileName);
        printf("\n");
    }
    else{
        strcpy(FileName, argv[1]);
    }

    if(loadProgramToMemory(FileName)){
        printf("\nCe fichier n'est pas un fichier d'instruction valide\n");
        return -1;
    }
    else{
        printf("\nFichier d'instruction charge\n");
    }

    //Decommenter la ligne suivante pour le programme strlen
    //add_string_to_memory(0x00400000, "Ecole de technologie superieure");

    //Decommenter les 4 lignes suivante pour le programme fmul
    //user_memory_save_word(0x00400000, 0x40490fdb);
    //user_memory_save_word(0x00400004, 0x449f2e14);
    //user_memory_save_word(0x00400008, 0x7F800000);
    //user_memory_save_word(0x0040000c, 0x007FFFFF);

    return CodeRun();
}