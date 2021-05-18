#include <vector>
#include <functional>
#include <queue>
#include <iostream>

using namespace std;

int kthSmallest(vector<int> &input, int k)
{
    int32_t result = 0;

    priority_queue<int, vector<int>> maxHeap;

    for (int i = 0; i < input.size(); i++)
    {
        maxHeap.push(input[i]);
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    return maxHeap.top();
}

int main()
{
    int k1 = 3, k2 = 6;
    vector<int> input{20, 8, 22, 4, 12, 10, 14};
    int left = kthSmallest(input, k1), right = kthSmallest(input, k2);

    cout << left << " " << right << endl;

    int result = 0;
    for (int i = 0; i < input.size(); i++)
        if (input[i] > left && input[i] < right)
            result += input[i];

    cout << result << endl;

    return 0;
}