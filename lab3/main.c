#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int size_mass = 15;
    int mass[size_mass];
    for (int i = 0; i < size_mass; i++)
    {
        mass[i] = rand() % 100;
        printf("%d ", mass[i]);
    }

    int sum_squared = 0;
    int* ptr_mass = mass;
    asm (
            "movq %[ptr_mass], %%rax;"
            "movl %[size_mass], %%ebx;"
        "main_loop:"
            "movl (%%rax), %%ecx;"
            "imull %%ecx, %%ecx;"
            "addl %%ecx, %[sum_squared];"
            "addq $4, %%rax;"
            "dec %%ebx;"
            "jne main_loop;"
            : [sum_squared] "+m" (sum_squared)
            : [ptr_mass] "m" (ptr_mass), [size_mass] "m" (size_mass)
            : "rax", "rbx", "rcx", "cc"
        );
    printf("\nSum of the squared elements of the array = %d
", sum_squared);
    return 0;
}