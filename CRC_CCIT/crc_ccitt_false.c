#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint16_t crc16(char* pData, int length);

int main(int argc, char *argv[]) {
    int dataLength = *argv[1] - 48;
    char *data = argv[2];
    

    for (int i = 0; i < dataLength; i++) {
        printf("0x%02X ", data[i]);
    }
    printf("\n");
    

    uint16_t crcVal = crc16(data, dataLength);

    printf("0x%5X\n", crcVal);

    return 0;
}

/*
 * From https://gist.github.com/tijnkooijmans/10981093
 */
uint16_t crc16(char* pData, int length) {
    uint8_t i;
    uint16_t wCrc = 0xffff;
    while (length--) {
        wCrc ^= *(unsigned char *)pData++ << 8;
        for (i=0; i < 8; i++)
            wCrc = wCrc & 0x8000 ? (wCrc << 1) ^ 0x1021 : wCrc << 1;
    }
    return wCrc & 0xffff;
}