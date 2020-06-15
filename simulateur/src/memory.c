//
// Created by alexa on 2020-06-05.
//

#include "memory.h"

//Prototpes fonctions privées
uint8_t stringToHex(char* string, uint32_t* hex);

uint32_t PC = 0;

uint32_t Register[REGISTER_NUMBER];
uint32_t Memory[MEMORY_SIZE];
uint32_t *userMemory;
uint32_t userMemorySize = 0;


//extern uint32_t Memory[MEMORY_SIZE];
//extern uint32_t *userMemory;
//extern uint32_t userMemorySize;

uint8_t loadProgramToMemory(char * file){
    uint8_t retVal = 0;
    uint8_t buffer[10];
    uint32_t count = 0;
    uint32_t hex = 0;

    FILE* program;

    program = fopen(file, "r");

    if(program == NULL){
        retVal = 1;
    }
    else {
        while (fgets(buffer, 10, program) && !retVal) {
            if (stringToHex(buffer, &Memory[count])) {
                retVal = 1;
            } else {
                count++;
            }
        }
        if (!retVal) {
            userMemory = &Memory[count];
            userMemorySize = MEMORY_SIZE - count;
        }
        fclose(program);
    }

    return retVal;
}

uint8_t stringToHex(char* string, uint32_t* hex){
    uint8_t retVal = 0;
    uint16_t i = 0;

    while(string[i] != '\0' && string[i] != '\n'){
        if(string[i] >= '0' && string[i] <= '9'){
            *hex = *hex << 4;
            *hex |= (string[i] - 48);
        }
        else if((string[i] | 0x20) >= 'a' && (string[i] | 0x20) <= 'f'){
            *hex = *hex << 4;
            switch(string[i] | 0x20){
                case 'a':
                    *hex |= 0x0a;
                    break;
                case 'b':
                    *hex |= 0x0b;
                    break;
                case 'c':
                    *hex |= 0x0c;
                    break;
                case 'd':
                    *hex |= 0x0d;
                    break;
                case 'e':
                    *hex |= 0x0e;
                    break;
                case 'f':
                    *hex |= 0x0f;
                    break;
            }
        }
        else{
            retVal = 1;
        }
        i++;
    }

    return retVal;
}

{

}

uint16_t memory_get_half_word(uint32_t addr){

}

uint32_t memory_get_word(uint32_t addr){

}

void memory_save_byte(uint32_t addr, uint8_t value){

}
void memory_save_half_word(uint32_t addr, uint16_t value){

}
void memory_save_word(uint32_t addr, uint32_t value){

}

