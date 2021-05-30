#include <iostream>
#include <vector>

using namespace std;

int minDifference(vector<int> &A, int element)
{
    int start = 0, end = A.size() - 1;

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

	return min(abs(element - A[start]), abs(element - A[end]));
}

int main() {
    vector<int> arr {3, 5, 7, 9, 10, 40, 70, 90, 100, 130, 140, 160, 170};
    int result = minDifference(arr, 65);
    cout << result << endl;
    return 0;
}