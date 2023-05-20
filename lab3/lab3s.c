#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL));
    const int size_mass = 15;
    int mass[size_mass];   
    for (int i = 0; i < size_mass; i++)
    {
        mass[i] = rand() % 100;
        printf("%d ", mass[i]);
    }
    printf("\n");
    int index;
    int max_number;
    int* ptr_mass = mass;
    asm (
            "movq %[ptr_mass], %%rax;"
            "movl %[size_mass], %%ebx;"
            "xorl %%ecx, %%ecx;"
            "movl (%%rax), %%edx;"
            "xorl %%edi, %%edi;"  
            
        "main_loop:"
            "movl (%%rax), %%esi;"
            "cmpl %%esi, %%edx;"
            "jg next;"
            "movl %%esi, %%edx;"
            "movl %%edi, %%ecx;"

        "next:"
            "inc %%edi;"
            "addq $4, %%rax;"
            "cmpl %%ebx, %%edi;"
            "jne main_loop;"
            "movl %%edx, %[max_number];"
            "movl %%ecx, %[index];"
            :
            :[size_mass]"m"(size_mass), [ptr_mass]"m"(ptr_mass),
                [index]"m"(index), [max_number]"m"(max_number)
            :
        );

    printf("Index max number = %d\n", index);
    printf("Max number = %d\n", max_number);
    return 0;
}
