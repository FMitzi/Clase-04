#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, char c);
char pop(Stack *s);
char peek(Stack *s);
void printStack(Stack *s);

#endif







