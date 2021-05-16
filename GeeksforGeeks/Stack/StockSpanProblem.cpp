#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> stockSpanProblem(vector<int> input)
{
    vector<int> result;

    stack<pair<int, int>> stack;

    for (int i = 0; i < input.size(); i++)
    {
        if (stack.size() == 0)
            result.push_back(-1);
        else if (stack.top().first > input[i])
            result.push_back(stack.top().second);
        else
        {
            while (stack.size() > 0 && stack.top().first <= input[i])
                stack.pop();
            result.push_back(stack.size() == 0 ? -1 : stack.top().second);
        }

        stack.push(make_pair(input[i], i));
    }

    for (int i = 0; i < result.size(); i++)
        result[i] = i - result[i];

    return result;
}

int main()
{
    vector<int> input{100, 80, 60, 70, 60, 75, 85};
    vector<int> result = stockSpanProblem(input);

    for (auto &arr : result)
        cout << arr << " ";

    return 0;
}