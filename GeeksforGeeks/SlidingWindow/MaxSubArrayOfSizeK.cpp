#include <iostream>
#include <vector>

using namespace std;

int maximumSumSubarray(vector<int> &arr, int K)
{
    int result = INT_MIN, sum = 0;
    int i = 0, j = 0, n = arr.size();
    while (j < n)
    {
        sum += arr[j];

        if (j - i + 1 == K)
        {
            result = max(result, sum);
            sum -= arr[i++];
        }

        j++;
    }

    return result;
}

int main()
{
    vector<int> arr{100, 200, 300, 400};
    cout << maximumSumSubarray(arr, 3) << endl;
    return 0;
}