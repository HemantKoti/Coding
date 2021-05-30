#include <iostream>

using namespace std;

int findCeil(int arr[], int n, int x)
{
    int low = 0, high = n - 1, mid;

    int ceil = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == x)
            return arr[mid];
        else if (x < arr[mid])
        {
            ceil = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ceil;
}

int findFloor(int arr[], int n, int x)
{
    int low = 0, high = n - 1, mid;

    int floor = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return arr[mid];
        else if (x < arr[mid])
            high = mid - 1;
        else
        {
            floor = arr[mid];
            low = mid + 1;
        }
    }

    return floor;
}

int main()
{
    int arr[] = {1, 4, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findFloor(arr, n, 7) << endl;
    cout << findFloor(arr, n, 10) << endl;
    cout << findFloor(arr, n, 1) << endl;
    cout << findFloor(arr, n, 0) << endl;
    cout << findFloor(arr, n, 5) << endl;

    cout << findCeil(arr, n, 7) << endl;
    cout << findCeil(arr, n, 10) << endl;
    cout << findCeil(arr, n, 1) << endl;
    cout << findCeil(arr, n, 0) << endl;
    cout << findCeil(arr, n, 5) << endl;

    return 0;
}