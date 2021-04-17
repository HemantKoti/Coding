
#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <conio.h>

#define MAXWL 20 /* Maximum length of a word */
#define MAXNO 25 /* Maximum No of words in a sentence */
#define CHARACTER_SIZE 256
#define IN 1
#define OUT 0
#define MAXLINESIZE 4096
#define MAXOP 1000
#define MAXVAL 1000
#define NUMBER '0'
#define MAX_SIZE 1000
#define SWAP(t, a, b) \
    t temp;           \
    temp = a;         \
    a = b;            \
    b = temp;

#endif