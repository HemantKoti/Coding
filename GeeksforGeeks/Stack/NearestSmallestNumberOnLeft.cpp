#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nearestSmallestLeft(vector<int> input)
{
    vector<int> result;

    stack<int> stack;

    for (int i = 0; i < input.size(); i++)
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
    vector<int> input{1, 6, 4, 10, 2, 5};
    vector<int> result = nearestSmallestLeft(input);

    for (auto &arr : result)
        cout << arr << " ";
    return 0;
}