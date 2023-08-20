#include <stdio.h>
#include <stdint.h>
#include <string.h>

unsigned long hashcode = 0x21DD09EC;

int main() {
    unsigned int ints[5];
    unsigned int remainder = hashcode % 5;
    unsigned int base_value = hashcode / 5;

    for (int i = 0; i < 5; i++) {
        ints[i] = base_value;
    }

    for (int i = 0; i < remainder; i++) {
        ints[i]++;
    }

    char password[21]; // 20 characters + null terminator
    int pos = 0;

    for (int i = 0; i < 5; i++) {
        memcpy(&password[pos], &ints[i], sizeof(unsigned int));
        pos += sizeof(unsigned int);
    }

    // Add null terminator at the end of the password
    password[20] = '\0';

    printf("%s", password);

    return 0;
}
