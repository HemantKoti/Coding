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
        else if (mid - 1 >= start && A[mid - 1] == element)
            return mid - 1;
        else if (mid + 1 <= end && A[mid + 1] == element)
            return mid + 1;
        else if (element > A[mid])
            start = mid + 2;
        else
            end = mid - 2;
    }

    return -1;
}

int main()
{
    vector<int> input{10, 3, 40, 20, 50, 80, 70};
    cout << binarySearchReverse(input, 40) << endl;
    cout << binarySearchReverse(input, 21) << endl;
    cout << binarySearchReverse(input, 70) << endl;
    cout << binarySearchReverse(input, 10) << endl;

    return 0;
}
