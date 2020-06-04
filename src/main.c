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

void AfficheEtatCourant()
{
}


char CodeRun() {
    char choix = 's';

    while (NextInstructionExist) {
        if (choix == 's') {
            printf("Exécution pas-à-pas (s) ou continue (c)\n");
            printf(">");
            scanf(" %c", &choix);
            fflush(stdin);
        }
        //NextInstructionExist = RunNextInstruction();
        if (choix == 's') AfficheEtatCourant();
    }
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