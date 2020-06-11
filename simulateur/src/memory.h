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
extern uint32_t Memory[MEMORY_SIZE];
extern uint32_t *userMemory;
extern uint32_t userMemorySize;
/**
 * Place les instructions contenu dans le fichier passée en entrée dans la mémoire et initialise les variables globales
 * userMemory et userMemorySize.
 * @param file : chaine de caratere donnant le chemin vers le fichier contenant le programme.
 * @return Différent de 0 s'il y a un erreur.
 */
uint8_t loadProgramToMemory(char * file);


#endif //RV32EM_SIMULATOR_MEMORY_H
