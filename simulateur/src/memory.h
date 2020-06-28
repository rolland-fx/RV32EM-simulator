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
extern uint32_t userMemorySize;

/**
 * Place les instructions contenu dans le fichier passée en entrée dans la mémoire et initialise les variables globales
 * userMemory et userMemorySize.
 * @param file : chaine de caratere donnant le chemin vers le fichier contenant le programme.
 * @return Différent de 0 s'il y a un erreur.
 */
uint8_t loadProgramToMemory(char * file);

/**
 * Test if the simulation have reach the end of the program
 * @return 1 if end of program is reach
 */
uint8_t is_end_of_program(void);

/**
 * Acces a byte of the simulated memory at the simulated address
 * @param addr : 32 bits  adress in the simulated memory
 * @return Return the byte at the adress in the memory
 */
uint8_t memory_get_byte(uint32_t addr);
/**
 * Acces two byte of the simulated memory at the simulated address
 * @param addr : 32 bits adress in the simulated memory
 * @return Return the 16 bits at the adress in the memory (N and N+1)
 */
uint16_t memory_get_half_word(uint32_t addr);
/**
 * Acces a 32 bit word of the simulated memory at the simulated address
 * @param addr : 32 bits adress in the simulated memory
 * @return Return the 32 bits at the adress in the memory (N to N+3)
 */
uint32_t memory_get_word(uint32_t addr);

/**
 * Store a byte in the simulated memory at the simulated address
 * @param addr : 32 bits adress in the simulated memory
 * @return Return the byte at the adress in the memory
 */
void memory_save_byte(uint32_t addr, uint8_t value);
/**
 * Store two byte in the simulated memory at the simulated address
 * @param addr : 32 bits adress in the simulated memory
 * @return Retur the two byte at the adress in the memory (N and N+1)
 */
void memory_save_half_word(uint32_t addr, uint16_t value);
/**
 * Store a word in the simulated memory at the simulated address
 * @param addr : 32 bits adress in the simulated memory
 * @return Return the word at the adress in the memory (N to N+3)
 */
void memory_save_word(uint32_t addr, uint32_t value);

uint8_t user_memory_get_byte(uint32_t addr);
uint16_t user_memory_get_half_word(uint32_t addr);
uint32_t user_memory_get_word(uint32_t addr);

/**
 * Store a byte in the simulated memory at the simulated address
 * This function can only acces the data memory
 * @param addr : 32 bits adress in the simulated data memory
 * @return Return the byte at the adress in the data memory
 */
void user_memory_save_byte(uint32_t addr, uint8_t value);
/**
 * Store the two byte in the simulated memory at the simulated address
 * This function can only acces the data memory
 * @param addr : 32 bits adress in the simulated data memory
 * @return Return two bytes at the adress in the data memory (N and N+1)
 */
void user_memory_save_half_word(uint32_t addr, uint16_t value);
/**
 * Store the the word in the simulated memory at the simulated address
 * This function can only acces the data memory
 * @param addr : 32 bits adress in the simulated data memory
 * @return Return the word at the adress in the data memory (N to N+3)
 */
void user_memory_save_word(uint32_t addr, uint32_t value);

/**
 * Store a string in the simulated data memory
 * Can be called before the execution of a program
 * to store data in the memory
 * @param addr : 32 bits adress in the simulated data memory
 * @param string : Pointer to the string to store
 * @return None
 */
void add_string_to_memory(uint32_t addr, char* string);

#endif //RV32EM_SIMULATOR_MEMORY_H
