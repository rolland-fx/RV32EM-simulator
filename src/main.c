#include "RV32EM.h"
char CodeRun() {
    char choix = 's';
    char MemoryAdressString[10];
    char *ptr;
    uint32_t MemoryAdress;
    uint8_t MemoryCaseToShow;
    NextInstructionExist = 1;
    while (NextInstructionExist) {
        if (choix != 'c') {
            printf("Execution pas-a-pas (s) ou continue (c)\n");
            printf(">");
            scanf(" %c", &choix);
            fflush(stdin);
        }
        //NEXT FUNCTION TO FINISH TO MAKE THE PROGRAM DO SOMEHTING !
        NextInstructionExist = RunNextInstruction();
        if (choix == 's') {
            PrintInstruction();
            PrintCurrentState();
        }
        else if (choix == 'm')
        {
            printf("Choix de l'adresse memoire a afficher. Format : FFFFFF \n");
            printf(">");
            scanf("%s", MemoryAdressString);
            printf("\n");
            fflush(stdin);
            printf("Nombre de case memoire a afficher\n");
            printf(">");
            scanf("%d", &MemoryCaseToShow);
            printf("\n");
            fflush(stdin);
            MemoryAdress = (uint32_t)strtol(MemoryAdressString, &ptr, 16);
            PrintSliceofMemory(MemoryAdress, MemoryCaseToShow);
            PrintInstruction();
            PrintCurrentState();
        }
    }
    PrintInstruction();
    PrintCurrentState();
    return 0;
}

int main(int argc, char *argv[] ) {
    char FileName[30];
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