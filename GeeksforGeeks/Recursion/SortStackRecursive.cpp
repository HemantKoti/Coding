#include <iostream>
#include <stack>

using namespace std;

void insert(stack<int> &stack, int temp)
{
    if (stack.size() == 0 || stack.top() <= temp)
    {
        stack.push(temp);
        return;
    }

    int val = stack.top();
    stack.pop();
    insert(stack, temp);
    stack.push(val);
}

void sort(stack<int> &stack)
{
    if (stack.size() == 0)
        return;

    int temp = stack.top();
    stack.pop();
    sort(stack);
    insert(stack, temp);
}

int main()
{
    stack<int> stack;
    stack.push(2);
    stack.push(5);
    stack.push(1);
    stack.push(3);
    stack.push(0);

    sort(stack);

    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }

    return 0;
}