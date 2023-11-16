#include "../includes/cpu.h"

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


    fseek(file, 0L, SEEK_SET);
    fclose(file);
}