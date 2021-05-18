#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void increment_base26(char s[], int len)
{
    int i = len - 1;
    while (i >= 0)
    {
        if (s[i] == 'z')
            s[i] = 'a';
        else
        {
            s[i] += 1;
            break;
        }
        i -= 1;
    }
}

void reverse(char s[], int len)
{
    for (int i = 0; i < len - 1 - i; ++i)
    {
        char t = s[i];
        int dest = len - 1 - i;
        s[i] = s[dest];
        s[dest] = t;
    }
}

char *next_lexicographic_palindrome(char s[])
{
    int len = strlen(s);
    int half = len / 2;
    int half_plus_mid = half + (len % 2);
    reverse(s, half);
    // printf("First reverse: %s\n", s);

    int cmp = strncmp(s, s + half_plus_mid, half);
    // printf("Compare: %d\n", cmp);

    if (cmp > 0)
        memcpy(s + half_plus_mid, s, half);
    // printf("First memcpy: %s\n", s);

    reverse(s, half);
    // printf("Second reverse: %s\n", s);

    if (cmp >= 0)
    {
        return s;
    }

    increment_base26(s, half_plus_mid);
    // printf("First Increment base: %s\n", s);

    reverse(s, half);
    // printf("Third reverse: %s\n", s);

    memcpy(s + half_plus_mid, s, half);
    // printf("Second memcpy: %s\n", s);

    reverse(s, half);
    // printf("Fourth reverse: %s\n", s);

    return s;
}

int main(int argc, char **argv)
{
    char s[] = "cbaba";
    printf("Next Lexicographic Palindrome: %s\n", next_lexicographic_palindrome(s));
    return 0;
}