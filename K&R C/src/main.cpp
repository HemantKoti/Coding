#include "../include/global.h"

int sp = 0; //stack position
double val[MAXVAL];

void reverseRecursive(char *str, int start, int end)
{
    char ch;
    if (start >= end)
        return;

    ch = *(str + start);
    *(str + start) = *(str + end);
    *(str + end) = ch;

    reverseRecursive(str, ++start, --end);
}

int implementRecursiveITOA(int n, char s[])
{
    int i = 0;

    if (n / 10 != 0)
        i = implementRecursiveITOA(n / 10, s);
    else if (n < 0)
        s[i++] = '-';

    s[i++] = abs(n % 10) + '0';
    s[i] = '\0';

    return i;
}

int implementStrindexRightmost(char s[], char t[])
{
    int i;
    int count = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == t[i])
        {
            count = i;
        }
    }
    return count;
}

int implementStrindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] = '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

double implementATOF(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

void escape()
{
    int c, index = 0;
    char str[MAX_SIZE];
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '\n':
            str[index++] = '\\';
            str[index++] = 'n';
            break;
        case '\t':
            str[index++] = '\\';
            str[index++] = 't';
            break;

        case '\b':
            str[index++] = '\\';
            str[index++] = 'b';
            break;
        default:
            str[index++] = c;
            break;
        }
    }
    str[index] = '\0';
    printf("The string is : %s\n", str);
    /*INPUT
    Hemant
    Koti
    Hemant  Koti
    Hemant\tKoti
    \bHemant*/
}

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Stack is full\n");
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("Stack is empty\n");
    }
    return 0;
}

void polishCalculator()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            push(pop() - pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("Can't divide by zero\n");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0)
            {
                push((int)pop() % (int)op2);
            }
            else
            {
                printf("Can't divide by zero\n");
            }
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Unknown Command\n");
            break;
        }
    }
}
int countNumberOfOneBits(int x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
        {
            b++;
        }
    }
    return b;
}
int implementStrpbrk(char s1[], char s2[])
{
    int i;
    int j;
    int pos;

    pos = -1;

    for (i = 0; pos == -1 && s1[i] != '\0'; i++)
    {
        for (j = 0; pos == -1 && s2[j] != '\0'; j++)
        {
            if (s2[j] == s1[i])
            {
                pos = i;
            }
        }
    }
    return pos;
}
void deleteAllOccurencesOfAStringFromAString(char s[], char s1[])
{
    int i, j, k, flag = 0;
    for (i = 0, j = 0; s[i] != '\0'; i++)
    {
        flag = 0;
        for (k = 0; s1[k] != '\0' && !flag; k++)
        {
            if (s1[k] == s[i])
            {
                flag = 1;
            }
        }
        if (!flag)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

void deleteAllOccurencesOfACharacterFromAString(char s[], int c)
{
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

void reverse(char *str)
{
    int c, i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

void implementITOA(int n, char s[])
{
    int i = 0, sign;
    if ((sign = n) < 0)
        n = -n;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int implementATOI(char s[])
{
    int i, n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
    {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

int implementStrlen(char s[])
{
    int i = 0;
    while (s[i++] != '\0')
        ;
    return i;
}

void rangesOfDataTypesUsingLimits()
{
    printf("\nBits of type char: %d\n\n", CHAR_BIT); /* IV */

    printf("Maximum numeric value of type char: %d\n", CHAR_MAX);   /* IV */
    printf("Minimum numeric value of type char: %d\n\n", CHAR_MIN); /* IV */

    printf("Maximum value of type signed char: %d\n", SCHAR_MAX);   /* IV */
    printf("Minimum value of type signed char: %d\n\n", SCHAR_MIN); /* IV */

    printf("Maximum value of type unsigned char: %u\n\n", (unsigned)UCHAR_MAX); /* SF */ /* IV */

    printf("Maximum value of type short: %d\n", SHRT_MAX);   /* IV */
    printf("Minimum value of type short: %d\n\n", SHRT_MIN); /* IV */

    printf("Maximum value of type unsigned short: %u\n\n", (unsigned)USHRT_MAX); /* SF */ /* IV */

    printf("Maximum value of type int: %d\n", INT_MAX);   /* IV */
    printf("Minimum value of type int: %d\n\n", INT_MIN); /* IV */

    printf("Maximum value of type unsigned int: %u\n\n", UINT_MAX); /* RB */ /* IV */

    printf("Maximum value of type long: %ld\n", LONG_MAX); /* RB */   /* IV */
    printf("Minimum value of type long: %ld\n\n", LONG_MIN); /* RB */ /* IV */

    printf("Maximum value of type unsigned long: %lu\n\n", ULONG_MAX); /* RB */ /* IV */
}

void reverseEveryLine()
{
    char str[MAXLINESIZE];
    while (fgets(str, MAXLINESIZE, stdin))
    {
        reverse(str);
        printf("%s\n", str);
    }
    /* INPUT
    Hello Wrld I m the cooles t guy ever..this ; jsuyt for
    0483
    testing//?*/
}

char *trimWhitespaces(char *str)
{
    char *end;
    // Trim leading space
    while (isspace(*str))
        str++;

    if (*str == '\0') // All spaces?
        return str;
    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end))
        end--;
    // Write new null terminator
    *(end + 1) = '\0';
    return str;
}

void removeLeadingAndTrailingWhitespaces()
{
    char str[MAXLINESIZE];
    char *temp;
    while (fgets(str, MAXLINESIZE, stdin))
    {
        temp = trimWhitespaces(str);
        if (*temp != '\0')
            printf("Truncated String : %s\n", temp);
    }
    /*INPUT
    			Hello			World
    Welcome to C			Programming


    			In K			And R C				*/
}

void findTheLongestLine()
{
    char str[MAXLINESIZE];
    char strOutput[MAXLINESIZE];
    int lineLength = 0, max = INT_MIN;
    while (fgets(str, MAXLINESIZE, stdin))
    {
        lineLength = strlen(str);
        if (max <= lineLength)
        {
            max = lineLength;
            strcpy(strOutput, str);
        }
    }
    printf("Longest Line = \"%s\" and its Length = %d", strOutput, lineLength);
    /*INPUT
    Hello World\t	Test\bProgram
    This should be the biggest line\bamong all\t
    Welcome to Progamming\t\bHello All*/
}

void countLinesWordsCharacters()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        nc++;
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            nw++;
        }
    }
    printf("Lines : %d, Words : %d, Characters : %d\n", nl, nw, nc);
    /* INPUT
    Hello Wrld I m the cooles t guy ever..this ; jsuyt for
    0483
    testing//?*/
}

void horizontalHistogramOfCharacterFrequencies()
{
    int characters[CHARACTER_SIZE];
    int i, c, j;

    for (i = 0; i < CHARACTER_SIZE; i++)
        characters[i] = 0;

    while ((c = getchar()) != EOF)
    {
        characters[c]++;
    }

    for (i = 0; i < CHARACTER_SIZE; i++)
    {
        if (characters[i] != 0)
        {
            putchar(i);
            for (j = 0; j < characters[i]; j++)
            {
                putchar('*');
            }
            putchar('\n');
        }
    }
    /* INPUT
    Hello Wrld I m the cooles t guy ever..this ; jsuyt for
    0483
    testing//?*/
}

void verticalHistogramOfWordLengths()
{
    int word[MAXNO];
    int i, c, j, wordLength = 0, noOfWords = 0;

    for (i = 0; i < MAXNO; i++)
        word[i] = 0;

    while ((c = getchar()) != EOF)
    {
        wordLength++;
        if (c == ' ' || c == '\n' || c == '\t')
        {
            word[noOfWords] = wordLength - 1;
            noOfWords++;
            wordLength = 0;
        }
    }

    for (i = MAXWL; i >= 1; i--)
    {
        for (j = 0; j <= noOfWords; j++)
        {
            if (i <= word[j])
                putchar('*');
            else
                putchar(' ');
        }
        putchar('\n');
    }
    /*INPUT
    I Love C Programming */
}

void replaceSpecialCharactersBySymbols()
{
    int c = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else
            putchar(c);
    }
    putchar('\n');
    /*INPUT
    Hemant	Koti\\b
    */
}

void replaceMultipleBlanksByASingleBlank()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
        {
            putchar(' ');
            while ((c = getchar()) != EOF)
            {
                if (c != ' ' && c != '\t')
                {
                    putchar(c);
                    break;
                }
            }
        }
        else
        {
            putchar(c);
        }
    }
    /* INPUT
    Replace  multiple spaces      with a single     space
    From	different		lines
    as	well 	*/
}

void countBlanksTabsNewlines()
{
    int countTabs = 0, countBlanks = 0, countNewlines = 0;
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            countNewlines++;
        else if (c == ' ')
            countBlanks++;
        else if (c == '\t')
            countTabs++;
    }
    printf("Number of new lines = %d and number of spaces = %d and number of tabs = %d\n", countNewlines, countBlanks, countTabs);
    /* INPUT
    Replace  multiple spaces      with a single     space
    From	different		lines
    as	well 	*/
}

void formatSpecifiers()
{
    printf("%6.0f\n", (15.0 / 9));
    printf("EOF value = %d\n", EOF);
}

int main()
{
    //formatSpecifiers();
    //countBlanksTabsNewlines();
    //replaceMultipleBlanksByASingleBlank();
    //replaceSpecialCharactersBySymbols();
    //verticalHistogramOfWordLengths();
    //horizontalHistogramOfCharacterFrequencies();
    //countLinesWordsCharacters();
    //findTheLongestLine();
    //removeLeadingAndTrailingWhitespaces();
    //reverseEveryLine();
    //rangesOfDataTypesUsingLimits();
    //deleteAllOccurencesOfACharacterFromAString("dhkadgkadosgfse",'d'); //error
    //deleteAllOccurencesOfAStringFromAString("dhkadgkadosgfse","dae"); //error
    int a = 5, b = 10;
    printf("A and B before swap are : %d and %d\n", a, b);
    SWAP(int, a, b);
    printf("A and B after swap are : %d and %d\n", a, b);
    return 0;
}
