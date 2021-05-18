#include <vector>
#include <functional>
#include <queue>
#include <iostream>

using namespace std;

int minimumCost(vector<int> &input)
{
    int32_t result = 0;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (auto &x : input)
        minHeap.push(x);

    while (minHeap.size() > 1)
    {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        result += (first + second);
        minHeap.push(first + second);
    }

    return result;
}

int main()
{
    int k = 4;
    vector<int> input{4, 3, 2, 6};
    cout << minimumCost(input) << endl;

    return 0;
}