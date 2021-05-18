#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int> &arr, int temp)
{
    if (arr.size() == 0 || arr.back() <= temp)
    {
        arr.push_back(temp);
        return;
    }

    int val = arr.back();
    arr.pop_back();
    insert(arr, temp);
    arr.push_back(val);
}

void sort(vector<int> &arr)
{
    if (arr.size() == 0)
        return;

    int temp = arr.back();
    arr.pop_back();
    sort(arr);
    insert(arr, temp);
}

int main()
{
    vector<int> arr{2, 5, 1, 3, 0};
    sort(arr);

    for (auto &x : arr)
        cout << x << " ";

    return 0;
}