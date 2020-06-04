#include "RV32EM.h"

#define DEBUG 1
void AffichageInitial()
{
    printf("Simulateur RISC-V RV32E par :\n");
    printf("- Alexandre Viau\n");
    printf("- Filipe Andres\n");
    printf("- F-X Rolland\n");
    printf("- Jean-Pascal Choiniere\n");
    printf("2020\n");
}

char CodeRun()
{
    return 0;
}

int main(int argc, char *argv[] ) {
    char FileName[30];
    FILE* HexaSourceFile;
    AffichageInitial();
    if (argv[1] == NULL)
    {
        printf("Entrez le nom du fichier a simuler:\n");
        scanf("%s", FileName);
        HexaSourceFile = fopen(FileName,"r");
    }
    else
    {
        HexaSourceFile = fopen(argv[1],"r");
    }
    if(HexaSourceFile == NULL)
    {
        printf("Ce fichier ne peut pas etre ouvert\n");
        return -1;
    }
    //MemoryCreation();
    //loadFile(HexaSourceFile);
    return CodeRun();
}