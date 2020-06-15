//
// Created by rolla on 2020-06-04.
//
#include "interface.h"

void InitialPrint()
{
    setbuf(stdout,0);
    printf("Simulateur RISC-V RV32E par :\n");
    printf("- Alexandre Viau\n");
    printf("- Filipe Andres\n");
    printf("- Jean-Pascal Choiniere\n");
    printf("- F-X Rolland\n");
    printf("2020\n");
}
void PrintInstruction()
{
    printf("Instruction : 0x%08x [xxxxxxxxxxxxxxx]\n",0x00a12023);
}

void PrintCurrentState()
{
    printf("PC : 0x%08x x1 : 0x%08x x2 : 0x%08x x3 : 0x%08x\n", Register[PC],Register[1],Register[2],Register[3]);
    printf("x4 : 0x%08x x5 : 0x%08x x6 : 0x%08x x7 : 0x%08x\n", Register[4],Register[5],Register[6],Register[7]);
    printf("x8 : 0x%08x x9 : 0x%08x x10: 0x%08x x11: 0x%08x\n", Register[8],Register[9],Register[10],Register[11]);
    printf("x12: 0x%08x x13: 0x%08x x14: 0x%08x x15: 0x%08x\n", Register[12],Register[13],Register[14],Register[15]);
}

void PrintSliceofMemory(uint32_t address, uint8_t MemoryCaseToShow)
{
    printf("contenu memoire :\n");
    for (uint32_t i = address; i < (uint32_t) address + MemoryCaseToShow; i+=4)
    {
        if(i < MEMORY_SIZE)
        {
            //printf("0x%08x : 0x%08x\n",i,Memory[i]);
            printf("0x%08x : 0x%08x\n",i,user_memory_get_word(i));
        }
    }
    printf("\n\n");
}