#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdbool>
#include <stack>
#include <iostream>

typedef struct Stack Stack;
typedef char mydatatype;

using namespace std;

// To-Do: Revisit and re-implement using your own data structure library
struct Stack
{
    mydatatype data;
    struct Stack *next;
};

Stack *push(Stack *top, mydatatype data)
{
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    temp->data = data;
    temp->next = top;
    return temp;
}

mydatatype pop(Stack **top)
{
    Stack *temp = *top;
    *top = temp->next;
    mydatatype res = temp->data;
    free(temp);
    return res;
}

void checkMatchingParenthesis(char expression[])
{
    bool isBalanced = true;
    Stack *top = NULL;
    int i;
    for (i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            top = push(top, expression[i]);
            continue;
        }
        if ((expression[i] == ')' || expression[i] == '}' || expression[i] == ']') && top)
        {
            char ch = pop(&top);
            switch (ch)
            {
            case '(':
                if (expression[i] != ')')
                {
                    isBalanced = false;
                }
                break;
            case '{':
                if (expression[i] != '}')
                {
                    isBalanced = false;
                }
                break;
            case '[':
                if (expression[i] != ']')
                {
                    isBalanced = false;
                }
                break;
            }
        }
    }
    if (isBalanced == false)
    {
        printf("NO\n");
        return;
    }
    if (top != NULL)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
}

void checkMatchingParenthesisCpp(string expression)
{
    bool isBalanced = true;
    stack<char> s;

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            s.push(expression[i]);
            continue;
        }

        if ((expression[i] == ')' || expression[i] == '}' || expression[i] == ']') && !s.empty())
        {
            const char c = s.top();
            s.pop();

            switch (c)
            {
            case '(':
                isBalanced = expression[i] == ')';
                break;
            case '{':
                isBalanced = expression[i] == '}';
                break;
            case '[':
                isBalanced = expression[i] == ']';
                break;
            }
        }
    }

    if (!isBalanced || !s.empty())
        cout << "No" << endl;
    else if (s.empty())
        cout << "Yes" << endl;
}

// https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string str;
        cin >> str;
        checkMatchingParenthesisCpp(str);
    }

    return EXIT_SUCCESS;
}
