//
// Created by rolla on 2020-06-04.
//
#include "RV32EM.h"

void AffichageInitial()
{
    printf("Simulateur RISC-V RV32E par :\n");
    printf("- Alexandre Viau\n");
    printf("- Filipe Andres\n");
    printf("- Jean-Pascal Choiniere\n");
    printf("- F-X Rolland\n");
    printf("2020\n");
}
void AfficheInstruction()
{
    printf("Instruction : 0x%08x [xxxxxxxxxxxxxxx]\n",0x00a12023);
}

void AfficheEtatCourant()
{
    printf("PC : 0x%08x x1 : 0x%08x x2 : 0x%08x x3 : 0x%08x\n", Register[PC],Register[1],Register[2],Register[3]);
    printf("x4 : 0x%08x x5 : 0x%08x x6 : 0x%08x x7 : 0x%08x\n", Register[4],Register[5],Register[6],Register[7]);
    printf("x8 : 0x%08x x9 : 0x%08x x10: 0x%08x x11: 0x%08x\n", Register[8],Register[9],Register[10],Register[11]);
    printf("x12: 0x%08x x13: 0x%08x x14: 0x%08x x15: 0x%08x\n", Register[12],Register[13],Register[14],Register[15]);
}

void AfficheMemoire(uint32_t adresse,char MemoryCaseToShow)
{
    printf("contenu memoire :");
    for (uint32_t i = adresse; i <= (uint32_t) adresse + MemoryCaseToShow; i++)
    {
        printf("%X : %X\n",i,Memory[i]);
    }
}