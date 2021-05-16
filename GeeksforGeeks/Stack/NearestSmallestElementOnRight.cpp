#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nearestSmallestRight(vector<int> input)
{
    vector<int> result;

    stack<int> stack;

    for (int i = input.size() - 1; i >= 0; i--)
    {
        if (stack.size() == 0)
            result.push_back(-1);
        else if (stack.top() < input[i])
            result.push_back(stack.top());
        else
        {
            while (stack.size() > 0 && stack.top() > input[i])
                stack.pop();
            result.push_back(stack.size() == 0 ? -1 : stack.top());
        }

        stack.push(input[i]);
    }

    return result;
}

int main()
{
    // vector<int> input{4, 8, 5, 2, 25};
    vector<int> input{13, 7, 6, 12};
    vector<int> result = nearestSmallestRight(input);

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << " ";
    return 0;
}