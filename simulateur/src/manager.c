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
        NextInstructionExist = RunNextInstruction();
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
    char ret_val = 0;
    type_t *NextInstructionType;
    if (PC <= (MEMORY_SIZE - userMemorySize))
    {
        decoder_instruction(memory_get_word(PC),NextInstructionType);
        ret_val = 1;
    }
    return ret_val;

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
