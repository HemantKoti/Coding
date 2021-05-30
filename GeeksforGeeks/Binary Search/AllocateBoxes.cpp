#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

bool isValid(vector<int> &A, int B, int max)
{
    int sum = 0, numStudents = 1;

    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (sum > max)
        {
            numStudents++;
            sum = A[i];
        }

        if (numStudents > B)
            return false;
    }

    return true;
}

int allocateBooks(vector<int> &A, int B)
{
    if (A.size() < B)
        return -1;

    int start = *(max_element(A.begin(), A.end()));
    int end = accumulate(A.begin(), A.end(), 0);
    for (auto &a : A)
        end += a;
    int result = INT_MAX;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(A, B, mid))
        {
            result = min(result, mid);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    return result;
}

int main()
{
    vector<int> arr{12, 34, 67, 90};
    int B = 2;
    cout << allocateBooks(arr, B);

    return 0;
}