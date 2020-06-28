//
// Created by rolla on 2020-06-05.
//

#ifndef RV32EM_SIMULATOR_INTERFACE_H
#define RV32EM_SIMULATOR_INTERFACE_H

#include <stdint.h>
#include <stdio.h>
#include "memory.h"


/**
 * Show general information at start time
 * @param None
 * @return None
 */
void InitialPrint(void);
/**
 * Show the hexa and decoded format of the current instruction
 * @param buffer : string for the decoded format of the instruction
 * @return None
 */
void PrintInstruction(char* buffer);
/**
 * Show current state of all registers
 * @param None
 * @return None
 */
void PrintCurrentState(void);
/**
 * Show MemoryCaseToShow of memory from address
 * @param address  : Address of memory to show
 * @param MemoryCaseToShow : Number of memory slice to show
 * @return None
 */
void PrintSliceofMemory(uint32_t address, uint8_t MemoryCaseToShow);


#endif //RV32EM_SIMULATOR_INTERFACE_H
