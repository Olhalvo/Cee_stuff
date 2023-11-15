#include "../includes/cpu.h"

Cpu_t *initCpu(char *source)
{
    Cpu_t* cpu = malloc(sizeof(Cpu_t));
    //Initialize CPU
    memset(cpu, 0x0, sizeof(cpu));
    //Zero out registers
    memset(cpu->registers, 0x0, sizeof((cpu->registers)));
    FILE* file = fopen(source, "rb");
    if(!file){
        fprintf(stderr, "File: %s, not found our couldn't be open\n");
        exit(1);
    }

}