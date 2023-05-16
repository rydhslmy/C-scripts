#include <stdio.h>
#include <stdint.h>
// #include <string.h>

int main(int argc, int *argv[]) {
    int args = argc-1;
    int input = *argv[1];
    int datLen = 0;
    
    while(input) {
        datLen = datLen*10 + ((input & 0xFF)-0x30); 
        input = input >> 8;
    }

    if (datLen > 255) {
        datLen = 255;
    }

    printf("Generating byte message with the length of %d bytes\n", datLen);

    printf("0x%02X ", datLen);
    for (int i = 0; i < datLen; i++) {
        printf("0x%02X ", i);
    }

    return 0;
}