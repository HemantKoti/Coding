#include <vector>
#include <iostream>

using namespace std;

int binarySearchReverse(vector<int> &A, int element)
{
    int start = 0, end = A.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (element == A[mid])
            return mid;
        else if (element > A[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> input{20, 17, 15, 14, 13, 12, 10, 9, 8, 4};
    cout << binarySearchReverse(input, 9) << endl;
    cout << binarySearchReverse(input, 21) << endl;
    cout << binarySearchReverse(input, 20) << endl;

    return 0;
}
