#ifndef CONVERSION_H
#define CONVERSION_H

#include "stack.h"

void infixToPostfix(char *infix, char *postfix);
void infixToPrefix(const char *infix, char *prefix);

void reverse(char *str);

void printProgressPostfix(const char *postfix, Stack *s);
void printProgressPrefix(const char *infix, const char *prefix, Stack *s);


#endif



