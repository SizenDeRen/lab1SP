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
        "movq %[ptr_mass], %%rax\n"       // Загружаем адрес массива в регистр RAX
        "movl %[size_mass], %%ecx\n"      // Загружаем размер массива в регистр ECX
        "xorl %%edx, %%edx\n"             // Обнуляем регистр EDX для хранения суммы квадратов
        "loop_start:\n"
        "cmpl $0, %%ecx\n"                 // Проверяем, остались ли еще элементы массива
        "je loop_end\n"                    // Если нет, переходим к концу цикла
        "movl (%%rax), %%ebx\n"            // Загружаем значение элемента массива в регистр EBX
        "imull %%ebx, %%ebx\n"             // Умножаем элемент на самого себя
        "addl %%ebx, %%edx\n"              // Добавляем квадрат элемента к сумме
        "addq $4, %%rax\n"                 // Переходим к следующему элементу массива
        "subl $1, %%ecx\n"                 // Уменьшаем счетчик оставшихся элементов на 1
        "jmp loop_start\n"                 // Переходим к началу цикла
        "loop_end:\n"
        "movl %%edx, %[sum]\n"             // Сохраняем сумму в выходную переменную
        : [sum] "=m" (sum)                  // Выходной операнд - сумма квадратов
        : [ptr_mass] "m" (ptr_mass), [size_mass] "m" (size_mass)
        : "%eax", "%ecx", "%edx", "%ebx"    // Регистры, которые используются в инлайн-ассемблере
    );

    printf("The sum of squares is: %d\n", sum);
    return 0;
}