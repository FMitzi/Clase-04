#include "conversion.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}


void printProgressPostfix(const char *postfix, Stack *s) {
    printf("Postfix so far: %s\n", postfix);
    printStack(s);
    printf("-----------------------\n");
}


void printProgressPrefix(const char *infix, const char *prefix, Stack *s) {
    char tempPrefix[MAX];
    strcpy(tempPrefix, prefix);
    reverse(tempPrefix); // Invertir el prefijo para imprimirlo correctamente
    printf("Prefix so far: %s\n", tempPrefix);
    printStack(s);
    printf("-----------------------\n");
}

// Invertir la cadena
void reverse(char *str) {
    int n = strlen(str);
    int i;
    for (i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}



void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char c;

    printf("\nConverting Infix to Postfix Step by Step:\n");
    printf("---------------------------------------\n");

    while ((c = infix[i++]) != '\0') {
        if (isdigit(c) || isalpha(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Quitar '(' del stack
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
        postfix[j] = '\0'; // Terminar la cadena actual de postfix
        printProgressPostfix(postfix, &s);
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
        postfix[j] = '\0'; // Actualizar el postfix
        printProgressPostfix(postfix, &s);
    }

    postfix[j] = '\0';
}



void infixToPrefix(const char *infix, char *prefix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char c;

    // Trabajar con una copia del infijo invertida
    char reversedInfix[MAX];
    strcpy(reversedInfix, infix);
    reverse(reversedInfix); 

    printf("\nConverting Infix to Prefix Step by Step:\n");
    printf("---------------------------------------\n");

    while ((c = reversedInfix[i++]) != '\0') {
        if (isdigit(c) || isalpha(c)) {
            prefix[j++] = c; // Si es operando, añádir al prefijo
        } else if (c == ')') {
            push(&s, c); // Si es ')', empújar al stack
        } else if (c == '(') {
    
            while (!isEmpty(&s) && peek(&s) != ')') {
                prefix[j++] = pop(&s);
            }
            pop(&s); // Quitar ')' del stack
        
		} else {
            // Procesar operadores
            while (!isEmpty(&s) && precedence(peek(&s)) > precedence(c)) {
                prefix[j++] = pop(&s);
            }
            push(&s, c);
        }
        prefix[j] = '\0'; 
        printProgressPrefix(infix, prefix, &s);
    }

    // Vaciar el stack restante
    while (!isEmpty(&s)) {
        prefix[j++] = pop(&s);
        prefix[j] = '\0';
        printProgressPrefix(infix, prefix, &s);
    }

    prefix[j] = '\0';
    reverse(prefix); // Invertir el prefijo al final
}













