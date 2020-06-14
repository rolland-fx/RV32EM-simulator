//
// Created by rolla on 2020-06-05.
//

#include "manager.h"

char CodeRun() {
    char Selection = 's';
    char InstructionCounter = 0;
    NextInstructionExist = 1;
    while (NextInstructionExist)
    {
        if (Selection != 'c') {
            printf("Execution pas-a-pas (s) ou continue (c)\n");
            printf(">");
            scanf(" %c", &Selection);
            fflush(stdin);
        }
        switch (Selection)
        {
            case 'm':
                MemoryChoice();
                NextInstructionExist = 1; //for whatever reason, without this, it exit the switch
                break;
            case 'q':
                NextInstructionExist = 0;
                //ClearMemory();
                break;
            default:
                break;
        }
        if (Selection != 'c')
        {
            PrintInstruction();
            PrintCurrentState();
        }
        InstructionCounter++;
        //NEXT FUNCTION TO FINISH TO MAKE THE PROGRAM DO SOMEHTING !
        //NextInstructionExist = RunNextInstruction();
    }
    if (Selection == 'c')
    {
        PrintInstruction();
        PrintCurrentState();
    }
    return InstructionCounter;
}

char RunNextInstruction(void)
{
    return 0;
}

void MemoryChoice(void)
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
}
