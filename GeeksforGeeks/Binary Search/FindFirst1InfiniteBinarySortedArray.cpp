#include <iostream>
#include <vector>

using namespace std;

int indexOfFirstOne(vector<int> &A, int start, int end) {
    int result = -1;

	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (1 == A[mid]) {
            result = mid;
            end = mid - 1;
        }			
		else if (1 < A[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
    
	return result;
}

int findPosition(vector<int> &arr, int key) {
    int low = 0, high = 1;
    int value = arr[low];

    while (value < key) {
        low = high;
        high *= 2;
        value = arr[high];
    }

    return indexOfFirstOne(arr, low, high);
}

int main() {

    vector<int> arr { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    int result = findPosition(arr, 1);

    if (result == -1)
        cout << "Element is not found"  << endl;
    else 
        cout << "Element found at index: " << result << endl;

    return 0;
}