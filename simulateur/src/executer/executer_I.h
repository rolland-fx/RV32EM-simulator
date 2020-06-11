//
// Created by alexa on 2020-06-11.
//

#ifndef RV32EM_SIMULATOR_EXECUTER_I_H
#define RV32EM_SIMULATOR_EXECUTER_I_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "../decoder.h"
#include "../memory.h"

/**
 * Decode l'instruction passé en paramètre et place les information de celle-ci dans ptr_struct
 * @param instruction
 * @param ptr_struct
 */
void executer_type_I_LOAD(struct_I* ptr_struct);

#endif //RV32EM_SIMULATOR_EXECUTER_I_H
