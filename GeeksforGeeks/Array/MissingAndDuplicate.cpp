#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void findMissingAndRepeat(vector<int>& input)
{
    for (int i = 0; i < input.size(); ) {
        if (input[i] != input[input[i] - 1])
            swap(input[i], input[input[i] - 1]);
        else 
            i++;
    }   

    for (int i = 0; i < input.size(); i++)
        if (input[i] != i + 1)
            cout << "Missing: " << (i + 1) << ". Duplicate: " << input[i] << endl;
}

int main()
{
    vector<int> input{4, 3, 6, 2, 1, 1};
    findMissingAndRepeat(input);

    return 0;
}