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
    return CodeRun();
}