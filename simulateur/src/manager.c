//
// Created by rolla on 2020-06-05.
//

#include "manager.h"

char CodeRun() {
    char buffer[50];
    char Selection = 's';
    NextInstructionExist = 1;
    char InstructionCounter = 0;
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
            case 'q':
                NextInstructionExist = 0;
                break;
            case 'm':
                MemoryChoice();
                NextInstructionExist = 1;
                break;
            default:
                NextInstructionExist = RunNextInstruction(buffer);
                InstructionCounter++;
                break;
        }

        if (Selection != 'c')
        {
            PrintInstruction(buffer);
            PrintCurrentState();
        }
    }
    if (Selection == 'c')
    {
        PrintCurrentState();
    }
    return InstructionCounter;
}

char RunNextInstruction(char* buffer)
{
    char ret_val = 0;
    type_t NextInstructionType;
    void* ptr_struct;
    if (PC < (MEMORY_SIZE - userMemorySize))
    {
        ptr_struct = decoder_instruction(memory_get_word(PC),&NextInstructionType);
        create_string_instruction(NextInstructionType, ptr_struct,memory_get_word(PC), buffer);
        execute_instruction(ptr_struct, NextInstructionType);
        ret_val = 1;
    }
    else{
        ret_val = 0;
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
