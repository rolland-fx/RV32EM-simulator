#include "RV32EM.h"
char CodeRun() {
    char choix = 's';
    char MemoryAdressString[7];
    uint32_t MemoryAdress;
    char MemoryCaseToShow;
    NextInstructionExist = 1;
    while (NextInstructionExist) {
        if (choix == 's') {
            printf("Exécution pas-à-pas (s) ou continue (c)\n");
            printf(">");
            scanf("%c", &choix);
            printf("\n");
            fflush(stdin);
        }
        //ManageRegisterPC();
        //NextInstructionExist = RunNextInstruction();
        if (choix == 's') {
            AfficheInstruction();
            AfficheEtatCourant();
        }
        else if (choix == 'm')
        {
            printf("Choix de l'adresse memoire a afficher. Format : FFFFFF \n");
            printf(">");
            scanf("%s", MemoryAdressString);
            printf("\n");
            fflush(stdin);
            printf("Nombre de case mémoire a afficher\n");
            printf(">");
            scanf("%c", MemoryCaseToShow);
            printf("\n");
            fflush(stdin);
            MemoryAdress = (uint32_t)strtol(MemoryAdressString, NULL, 16);
            AfficheInstruction();
            AfficheEtatCourant();
            AfficheMemoire(MemoryAdress,MemoryCaseToShow);
        }
    }
    AfficheInstruction();
    AfficheEtatCourant();
    return 0;
}

int main(int argc, char *argv[] ) {
    char FileName[30];
    AffichageInitial();
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