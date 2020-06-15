//
// Created by rolla on 2020-06-05.
//

#ifndef RV32EM_SIMULATOR_INTERFACE_H
#define RV32EM_SIMULATOR_INTERFACE_H

#include <stdint.h>
#include <stdio.h>
#include "memory.h"

//extern uint32_t Register[REGISTER_NUMBER];
//extern uint32_t Memory[MEMORY_SIZE];

/**
 * Affiche les informations générale au lancement du programme
 * @param None
 * @return None
 */
void InitialPrint(void);
/**
 * Affiche pour l'instruction courante son format hexa et son decodage sous forme assembler
 * @param None
 * @return None
 */
void PrintInstruction(void);
/**
 * Affiche l'état courant des registres
 * @param None
 * @return None
 */
void PrintCurrentState(void);
/**
 * Affiche la valeur de x=MemoryCaseToShow a partir de l'adresse address de la mémoire simulée
 * @param address  : adresse au format du tableau de memoire simulée
 * @param MemoryCaseToShow : Nombre de case mémoire a afficer depuis address
 * @return None
 */
void PrintSliceofMemory(uint32_t address, uint8_t MemoryCaseToShow);


#endif //RV32EM_SIMULATOR_INTERFACE_H
