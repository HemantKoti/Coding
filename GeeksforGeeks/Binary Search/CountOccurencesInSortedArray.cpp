#include <iostream>

using namespace std;

int firstOccurrence(int nums[], int n, int target)
{
    int result = -1, low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target == nums[mid])
        {
            result = mid;
            high = mid - 1;
        }
        else if (target < nums[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return result;
}

int lastOccurrence(int nums[], int n, int target)
{
    int result = -1, low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target == nums[mid])
        {
            result = mid;
            low = mid + 1;
        }
        else if (target < nums[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return result;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 2, 3};
    int x = 2, n = sizeof(arr) / sizeof(arr[0]);
    int last = lastOccurrence(arr, n, x), first = firstOccurrence(arr, n, x);
    if (last == -1 || first == -1)
        return 0;
    return last - first + 1;
}