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
void AfficheInstruction()
{
    printf("Instruction : 0x%08x [xxxxxxxxxxxxxxx]",15);

}

void AfficheEtatCourant()
{
    printf("PC : 0x%08x x1 : 0x%08x x2 : 0x%08x x3 : 0x%08x\n", Register[16],Register[1],Register[2],Register[3]);
    printf("x4 : 0x%08x x5 : 0x%08x x6 : 0x%08x x7 : 0x%08x\n", Register[4],Register[5],Register[6],Register[7]);
    printf("x8 : 0x%08x x9 : 0x%08x x10 : 0x%08x x11 : 0x%08x\n", Register[8],Register[9],Register[10],Register[11]);
    printf("x12 : 0x%08x x13 : 0x%08x x14 : 0x%08x x15 : 0x%08x\n", Register[12],Register[13],Register[14],Register[15]);
}


char CodeRun() {
    char choix = 's';
    NextInstructionExist = 1;
    while (NextInstructionExist) {
        if (choix == 's') {
            printf("Exécution pas-à-pas (s) ou continue (c)\n");
            printf(">");
            scanf(" %c", &choix);
            fflush(stdin);
        }
        ManageRegisterPC();
        NextInstructionExist = RunNextInstruction();
        if (choix == 's') {
            AfficheInstruction();
            AfficheEtatCourant();
        }
    }
    AfficheInstruction();
    AfficheEtatCourant();
    return 0;
}

int main(int argc, char *argv[] ) {
    char FileName[30];
    FILE* HexaSourceFile;
    AffichageInitial();
    if (argv[1] == NULL)
    {
        printf("Entrez le nom du fichier a simuler:\n");
        printf(">");
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
    if(loadFile(HexaSourceFile) == -1)
    {
        printf("Ce fichier n'est pas un fichier d'instruction valide\n");
        return -1;
    } else{
        printf("Fichier d'instruction charge\n");
    }
    if(MemoryCreation() == -1)
    {
        printf("L'espace memoire n'a pas pu être cree\n");
        return -1;
    } else{
        printf("La memoire a ete cree\n");
    }
    fclose (HexaSourceFile);
    return CodeRun();
}