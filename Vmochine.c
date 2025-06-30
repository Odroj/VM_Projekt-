#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
// This is a simple virtual machine implementation in C

bool running=true; 

typedef enum{
    PSH,
    ADD,
    POP,
    SET,
    HLT
}InstructionSet; 

const int program[]={
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

int ip = 0; // Instruction pointer
int sp=-1; // Stack pointer
int stack[256]; // Stack memory

int fetch(){
    return program[ip]; 
}
void eval(int instr){
    switch (instr){
        case HLT: {
            running =false; 
            break; 
        }
        case PSH: {
            sp++;
            stack[sp]=program[++ip];
            break;
        }
        case POP: {
            int val_popped=stack[sp--];
            printf("Popped %d\n", val_popped);
            break;
        }
        case ADD: {
            int a= stack[sp--];
            int b= stack[sp--];
            int result =b+a; 
            sp++;
            stack[sp]=result;
            break;
        }
    }
}
int main(){
    while(running){
        eval(fetch());
        ip++; 
    }
}
