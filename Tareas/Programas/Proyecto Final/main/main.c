#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "conversion.h"

void removeSpaces(char *input, char *output) {
    int i, j = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (!isspace(input[i])) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

int main(int argc, char *argv[]) {
    char infix[MAX], postfix[MAX], prefix[MAX];

    if (argc != 2) {
        printf("Uso: %s <expresion_infix>\n", argv[0]);
        return 1;
    }
    
    char cleanedInfix[MAX];
    removeSpaces(argv[1], cleanedInfix);

    printf("Expresión infija limpia: %s\n", cleanedInfix);
    
    infixToPostfix(cleanedInfix, postfix);
    infixToPrefix(cleanedInfix, prefix);

    printf("\nResultados:\n");
    printf("Infix: %s\n", cleanedInfix);
    printf("Postfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);

    return 0;
} 







