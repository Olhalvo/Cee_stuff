#ifndef CPU_H
#define CPU_H

#include<stdint.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

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

enum Opcodes{
    NOOP,
    HALT,
    MOV,
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    NOT,
    SR,
    SL,
    MUL,
    PUSH,
    POP,
    INC,
    DEC,
};

#ifndef _TYPES_H_
#define _TYPES_H_

enum Size{
    Byte, //8
    Short, //16
    Dword, //32
};

enum Type{
    Reg,
    Imm,
};
#endif// _TYPES_H_




typedef struct _Cpu{
   uint32_t registers[REGISTER_COUNT_];
   uint8_t* codeBase;
   uint8_t* stackBase;
   size_t codeSize;
   size_t stackSize;
   size_t bytecodeSize;
   bool running;
} Cpu_t;

typedef struct _Instruction{
    uint8_t opcode;
    uint8_t destination;
    uint8_t source;
    uint8_t sourceType;
    bool isDstPtr;
    bool isSrcPtr;
    uint8_t sourceSize;
    uint32_t imm;
    uint8_t size;
} Instruction_t;

Cpu_t* initCpu(char* source);
void destroyCpu(Cpu_t* cpu);
void runCpu(Cpu_t* cpu);


#endif //CPU_H_