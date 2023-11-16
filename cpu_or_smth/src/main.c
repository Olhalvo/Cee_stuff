#include<stdio.h>
#include "../includes/cpu.h"
#include <stdint.h>

int main(){
    Cpu_t* cpu = initCpu("main.bc");
    destroyCpu(cpu);
    return EXIT_SUCCESS;
}