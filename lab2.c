#include <stdio.h>

int main() {
    unsigned char arr[] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, 0x01, 0x23, 0x45, 0x67};
    int count = 0;

    for (int i = 0; i < 12; i++) {
        unsigned char b = arr[i];
        if ((b & 0x22) == 0x00) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}