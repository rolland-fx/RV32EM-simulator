#include "RV32EM.h"

void add_string_to_memory(uint32_t addr, char* string){
    uint16_t i;

    for(i = 0; string[i] != '\0'; i++){
        user_memory_save_byte(addr++, (uint8_t)string[i]);
    }

    user_memory_save_byte(addr, string[i]);
}

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
    add_string_to_memory(0x00400000, "Ecole de technologie superieure");
    return CodeRun();
}