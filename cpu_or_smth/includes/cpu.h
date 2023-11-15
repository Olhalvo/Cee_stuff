#ifndef CPU_H
#define CPU_H

#include<stdint.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define REGISTER_COUNT_ 12 
#define PAGE_SIZE_ 4096

enum Registers_Enum{
    AX,
    BX,
    CX,
    DX,
    EX,
    FX,
    GX,
    HX,
    ESP,
    BP,
    IP,
    flags,
};

typedef struct _Cpu{
   uint32_t registers[REGISTER_COUNT_];
   uint8_t* codeBase;
   uint8_t* stackBase;
   size_t codeSize;
   size_t stackSize;
   size_t bytecodeSize;
} Cpu_t;

Cpu_t* initCpu(char* source);



#endif //CPU_H_