#include "../includes/cpu.h"

void fecth(Instruction_t *buff);
void execute(Instruction_t *inst);



Cpu_t *initCpu(char *source)
{
    Cpu_t* cpu = malloc(sizeof(Cpu_t));
    //Initialize CPU
    memset(cpu, 0x0, sizeof(cpu));
    //Zero out registers
    memset(cpu->registers, 0x0, sizeof((cpu->registers)));
    FILE* file = fopen(source, "r");

    if(!file){
        fprintf(stderr, "File: %s, not found or couldn't be open\n", source);
        exit(1);
    }
    fseek(file, 0L, SEEK_END);

    size_t fileSize = ftell(file);
    
    cpu->codeSize = (PAGE_SIZE_ * ( 1 + (fileSize / PAGE_SIZE_)));
    cpu->stackSize = PAGE_SIZE_;

    cpu->codeBase = malloc(cpu->stackSize + 10 + cpu->codeSize);
    
    fseek(file, 0L, SEEK_SET);
    fread((char*)cpu->codeBase, sizeof(unsigned char), fileSize, file);
    fclose(file);

    cpu->bytecodeSize = fileSize;
    cpu->stackBase = cpu->codeBase + cpu->codeSize;
    memset(cpu->stackBase, 0x00, sizeof(cpu->stackSize) + 10);


    cpu->registers[ESP] = cpu->codeSize;
    cpu->registers[BP] = cpu->codeSize;
    cpu->registers[IP] = 0;

    return cpu;
}

void destroyCpu(Cpu_t *cpu){
    free(cpu->codeBase);
    free(cpu);
}

void runCpu(Cpu_t *cpu){
    Instruction_t * instBuff = (Instruction_t*) malloc(sizeof(Instruction_t));
    while(cpu->running){

    }
}