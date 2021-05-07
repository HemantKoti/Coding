#include <iostream>
#include <vector>

using namespace std;

void josephus(int n, int k, int index, vector<int> &result)
{
    if (result.size() == 1)
        return;

    index = (index + k) % result.size();
    result.erase(result.begin() + index);
    josephus(n, k, index, result);
}

int main()
{
    vector<int> result;
    int n = 40, k = 7, index = 0;

    for (int i = 0; i < n; i++)
        result.push_back(i + 1);

    josephus(n, k - 1, index, result);

    cout << result[0];

    return 0;
}