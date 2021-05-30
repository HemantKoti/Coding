#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<long long> printFirstNegativeInteger(vector<long long> &A, long long int N, long long int K)
{
    vector<long long> result;
    queue<long long> q;
    int i = 0, j = 0;

    while (j < N)
    {
        if (A[j] < 0)
            q.push(A[j]);

        if (j - i + 1 == K)
        {
            result.push_back((q.empty() ? 0 : q.front()));
            if (A[i] < 0)
                 q.pop();
            i++;
        }

        j++;
    }

    return result;
}

int main()
{
    int K = 2;
    vector<long long> arr{-8, 2, 3, -6, 10};
    vector<long long> result = printFirstNegativeInteger(arr, arr.size(), K);
    for(auto &x : result)
        cout << x << " ";
    cout << endl;
    return 0;
}