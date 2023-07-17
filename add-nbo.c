#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t readNumberFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error to open: %s\n", filename);
        exit(1);
    }

    uint32_t number;
    fread(&number, sizeof(number), 1, file);
    fclose(file);

    return ntohl(number);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: add-nbo <file1> <file2>\n");
        return 1;
    }

    const char* file1 = argv[1];
    const char* file2 = argv[2];

    uint32_t number1 = readNumberFromFile(file1);
    uint32_t number2 = readNumberFromFile(file2);

    uint32_t sum = number1 + number2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", number1, number1, number2, number2, sum, sum);

    return 0;
}

