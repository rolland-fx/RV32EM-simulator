#include "RV32EM.h"

void add_string_to_memory(uint32_t addr, char* string){
    uint16_t i;

    for(i = 0; string[i] != '\0'; i++){
        user_memory_save_byte(addr++, (uint8_t)string[i]);
    }

    user_memory_save_byte(addr, string[i]);
}

int main(int argc, char *argv[] ) {
    char FileName[30];
    setbuf(stdout,0);
    InitialPrint();
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

    add_string_to_memory(0x00400000, "Ecole de technologie superieure");

    /*user_memory_save_byte(0x00400000, 'E');
    user_memory_save_byte(0x00400001, 'c');
    user_memory_save_byte(0x00400002, 'o');
    user_memory_save_byte(0x00400003, 'l');
    user_memory_save_byte(0x00400004, 'e');
    user_memory_save_byte(0x00400005, ' ');
    user_memory_save_byte(0x00400006, 'd');
    user_memory_save_byte(0x00400007, 'e');
    user_memory_save_byte(0x00400008, ' ');
    user_memory_save_byte(0x00400009, 't');
    user_memory_save_byte(0x0040000a, 'e');
    user_memory_save_byte(0x0040000b, 'c');
    user_memory_save_byte(0x0040000c, 'h');
    user_memory_save_byte(0x0040000d, 'n');
    user_memory_save_byte(0x0040000e, 'o');
    user_memory_save_byte(0x0040000f, 'l');
    user_memory_save_byte(0x00400010, 'o');
    user_memory_save_byte(0x00400011, 'g');
    user_memory_save_byte(0x00400012, 'i');
    user_memory_save_byte(0x00400013, 'e');
    user_memory_save_byte(0x00400014, ' ');
    user_memory_save_byte(0x00400015, 's');
    user_memory_save_byte(0x00400016, 'u');
    user_memory_save_byte(0x00400017, 'p');
    user_memory_save_byte(0x00400018, 'e');
    user_memory_save_byte(0x00400019, 'r');
    user_memory_save_byte(0x0040001a, 'i');
    user_memory_save_byte(0x0040001b, 'e');
    user_memory_save_byte(0x0040001c, 'u');
    user_memory_save_byte(0x0040001d, 'r');
    user_memory_save_byte(0x0040001e, 'e');
    user_memory_save_byte(0x0040001f, '\0');*/

    return CodeRun();
}