//
// Created by alexa on 2020-06-05.
//

#ifndef RV32EM_SIMULATOR_MEMORY_H
#define RV32EM_SIMULATOR_MEMORY_H

#include <stdint.h>
#include <stdio.h>

#define REGISTER_NUMBER 17

#define MEMORY_SIZE     0x1000000

extern uint32_t PC;

extern uint32_t Register[REGISTER_NUMBER];

/**
 * Place les instructions contenu dans le fichier passée en entrée dans la mémoire et initialise les variables globales
 * userMemory et userMemorySize.
 * @param file : chaine de caratere donnant le chemin vers le fichier contenant le programme.
 * @return Différent de 0 s'il y a un erreur.
 */
uint8_t loadProgramToMemory(char * file);

uint8_t memory_get_byte(uint32_t addr);
uint16_t memory_get_half_word(uint32_t addr);
uint32_t memory_get_word(uint32_t addr);

void memory_save_byte(uint32_t addr, uint8_t value);
void memory_save_half_word(uint32_t addr, uint16_t value);
void memory_save_word(uint32_t addr, uint32_t value);

uint8_t user_memory_get_byte(uint32_t addr);
uint16_t user_memory_get_half_word(uint32_t addr);
uint32_t user_memory_get_word(uint32_t addr);

void user_memory_save_byte(uint32_t addr, uint8_t value);
void user_memory_save_half_word(uint32_t addr, uint16_t value);
void user_memory_save_word(uint32_t addr, uint32_t value);


#endif //RV32EM_SIMULATOR_MEMORY_H
