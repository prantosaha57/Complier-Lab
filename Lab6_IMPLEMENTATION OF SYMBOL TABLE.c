#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char str[100];
    int i = 0;
    void *ptr;

    printf("Enter a $-terminated statement: ");
    //fgets(str, sizeof(str), stdin);
    gets(str);
    int n = strlen(str);

    printf("Entered statement: ");
    for (i = 0; i < n-1; i++) {
        printf("%c", str[i]);
    }

    printf("\n\n-------------------------------------\n");
    printf("|           Symbol Table            |\n");
    printf("-------------------------------------\n");
    printf("|  Symbol  |  Address  |    Type    |\n");
    printf("-------------------------------------\n");

    i = 0;
    while (str[i] != '$') {
        char token[15];
        int j = 0;

        while (str[i] == ' ') {
            i++;
        }

        while (str[i] != ' ' && str[i] != '\0' && str[i] != '$') {
            token[j] = str[i];
            i++;
            j++;
        }
        token[j] = '\0';

        if (isalnum(token[0])) {
            ptr = malloc(strlen(token) + 1);
            strcpy(ptr, token);
            printf("|   %s   | %#010x | Identifier |\n", token, (unsigned int)ptr);
        } else if (strchr("+-*/=", token[0]) != NULL) {
            ptr = malloc(strlen(token) + 1);
            strcpy(ptr, token);
            printf("|   %s     | %#010x |  Operator  |\n", token, (unsigned int)ptr);
        }

        if (str[i] == ' ') {
            i++;
        }
    }

    printf("-------------------------------------\n");

    return 0;
}

