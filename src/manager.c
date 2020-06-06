//
// Created by rolla on 2020-06-05.
//

#include "manager.h"

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
        //NextInstructionExist = RunNextInstruction();
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

char RunNextInstruction(void)
{
    ManageRegisterPC(0);
    return 0;
}
char ManageRegisterPC(char NextInstructionExist)
{
    if (NextInstructionExist >= 0)
    {
        Register[PC] += NextInstructionExist;
        return NextInstructionExist;
    }
    return -1;
}
