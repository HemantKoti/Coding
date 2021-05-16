#include <vector>
#include <functional>
#include <queue>
#include <iostream>

using namespace std;

vector<int> sortKSorted(vector<int> &input, int k) {
    vector<int> result;

    priority_queue<int, vector<int>, greater<int>> minheap;

    for (int i = 0; i < input.size(); i++) {
        minheap.push(input[i]);
        if (minheap.size() > k) {
            result.push_back(minheap.top());
            minheap.pop();
        }
    }

    while (minheap.size() != 0) {
        result.push_back(minheap.top());
        minheap.pop();
    }
    
    return result;
} 

int main()
{
    int k = 4;
    vector<int> input { 10, 9, 8, 7, 4, 70, 60, 50 };
    vector<int> result = sortKSorted(input, k);
    
    for (auto &x : result)
        cout << x << endl;

    return 0;
}