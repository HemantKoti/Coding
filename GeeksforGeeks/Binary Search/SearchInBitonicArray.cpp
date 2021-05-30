#include <vector>
#include <iostream>

using namespace std;

int binarySearchReverse(vector<int> &A, int start, int end, int element)
{
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

int binarySearch(vector<int> &A, int start, int end, int element)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (element == A[mid])
            return mid;
        else if (element < A[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int peakIndex(vector<int> &A)
{
    int n = A.size();
    int start = 0, end = n - 1;

    while (start < end)
    {
        if (start + 1 == end)
            return A[start] > A[end] ? start : end;

        int mid = start + (end - start) / 2;

        if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
            return mid;
        else if (A[mid - 1] > A[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return start;
}

int main()
{
    vector<int> arr{8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1, 0};
    int element = 2;

    int peak = peakIndex(arr);
    if (arr[peak] == element)
        cout << peak << endl;

    int left = binarySearch(arr, 0, peak, element);
    int right = binarySearchReverse(arr, peak + 1, arr.size() - 1, element);

    if (left == -1 && left == right)
        cout << -1 << endl;

    cout << (left == -1 ? right : left) << endl;
}