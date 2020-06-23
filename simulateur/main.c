#include "RV32EM.h"

int main(int argc, char *argv[] ) {
    char FileName[30];
    setbuf(stdout,0);
    InitialPrint();
    if (argv[1] == NULL)
    {
        printf("Entrez le nom du fichier a simuler:\n");
        printf(">");
        scanf("%s", FileName);
        printf("\n");
    }
    else
    {
        strcpy(FileName, argv[1]);
    }

    if(loadProgramToMemory(FileName))
    {
        printf("\nCe fichier n'est pas un fichier d'instruction valide\n");
        return -1;
    } else{
        printf("\nFichier d'instruction charge\n");
    }

    user_memory_save_byte(0x00400000, 'A');
    user_memory_save_byte(0x00400001, 'l');
    user_memory_save_byte(0x00400002, 'l');
    user_memory_save_byte(0x00400003, '0');
    user_memory_save_byte(0x00400004, '\0');

    return CodeRun();
}