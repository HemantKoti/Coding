#include "../../include/interviewbit.h"

bool binarySearchExists(vector<int> &b, int &x)
{
    int low = 0, high = b.size() - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (b[mid] < x)
            low = mid + 1;
        else if (b[mid] > x)
            high = mid;
        else
            return true;
    }

    if (b[low] == x)
        return low;

    return false;
}

int binarySearch(vector<int> &b, int &x)
{
    int low = 0, high = b.size() - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (b[mid] < x)
            low = mid + 1;
        else if (b[mid] > x)
            high = mid;
        else
            return mid;
    }

    if (b[low] == x)
        return low;

    return -1;
}
