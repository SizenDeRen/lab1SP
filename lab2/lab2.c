#include <stdio.h>

int main() {
    unsigned char arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 255};
    int count = 0;

    for (int i = 0; i < 10; i++) {
        unsigned char b = arr[i] | 0b01101011;
        if (b < 128) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}