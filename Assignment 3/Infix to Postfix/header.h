#define _CRT_SECURE_NO_WARNINGS

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

typedef struct infix
{
    char target[MAX] ;
    char stack[MAX] ;
    char *s, *t ;
    int top ;
} INFIX;

void initinfix (INFIX *ptr_head);
void setexpr (INFIX *ptr_head, char *str);
void push (INFIX *ptr_head, char c);
char pop (INFIX *ptr_head);
void convert (INFIX *ptr_head);
int priority (char c);
void show (INFIX ptr_head);
int evaluatePostFixExpression (INFIX *ptr_head, char *expr);

#endif