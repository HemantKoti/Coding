#include <iostream>
#include <vector>

using namespace std;

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

int findPosition(vector<int> &arr, int key) {
    int low = 0, high = 1;
    int value = arr[low];

    while (value < key) {
        low = high;
        high *= 2;
        value = arr[high];
    }

    return binarySearch(arr, low, high, key);
}

int main() {
    vector<int> arr {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int result = findPosition(arr, 10);

    if (result == -1)
        cout << "Element is not found"  << endl;
    else 
        cout << "Element found at index: " << result << endl;

    return 0;
}