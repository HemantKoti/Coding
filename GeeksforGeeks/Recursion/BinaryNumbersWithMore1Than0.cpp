#include <string>
#include <vector>
#include <iostream>

using namespace std;

void NBitBinaryUtil(int N, int one, int zero, string output, vector<string> &result)
{
    if (N == 0)
    {
        result.push_back(output);
        return;
    }

    string output1 = output + '1';
    NBitBinaryUtil(N - 1, one + 1, zero, output1, result);

    if (one > zero)
    {
        string output2 = output + '0';
        NBitBinaryUtil(N - 1, one, zero + 1, output2, result);
    }
}

int main()
{
    int N = 5;

    vector<string> result;
    int zero = 0, one = 0;
    string output = "";
    NBitBinaryUtil(N, one, zero, output, result);

    for (auto &x : result)
        cout << x << endl;
    return 0;
}