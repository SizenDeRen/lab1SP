#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    const int size_mass = 15;
    int mass[size_mass];
    for (int i = 0; i < size_mass; i++) {
        mass[i] = rand() % 100;
        printf("%d ", mass[i]);
    }
    printf("\n");

    int sum = 0;
    int* ptr_mass = mass;

    asm (
        "movq %[ptr_mass], %%rax\n"       
        "movl %[size_mass], %%ecx\n"      
        "xorl %%edx, %%edx\n"             
        "loop_start:\n"
        "cmpl $0, %%ecx\n"                 
        "je loop_end\n"                   
        "movl (%%rax), %%ebx\n"           
        "imull %%ebx, %%ebx\n"           
        "addl %%ebx, %%edx\n"            
        "addq $4, %%rax\n"                
        "subl $1, %%ecx\n"                
        "jmp loop_start\n"                
        "loop_end:\n"
        "movl %%edx, %[sum]\n"            
        : [sum] "=m" (sum)                 
        : [ptr_mass] "m" (ptr_mass), [size_mass] "m" (size_mass)
        : "%eax", "%ecx", "%edx", "%ebx"   
    );

    printf("The sum of squares is: %d\n", sum);
    return 0;
}
