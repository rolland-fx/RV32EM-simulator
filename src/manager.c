//
// Created by rolla on 2020-06-05.
//

#include "manager.h"


char RunNextInstruction(void)
{
    ManageRegisterPC(0);
    return 0;
}
char ManageRegisterPC(char NextInstructionExist)
{
    if (NextInstructionExist >= 0)
    {
        Register[PC] += NextInstructionExist;
        return NextInstructionExist;
    }
    return -1;
}
