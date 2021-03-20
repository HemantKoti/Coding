#include <iostream>
#include <string>

using namespace std;

void printPermutations(string str, string prefix)
{

    if (str.size() == 0)
        cout << prefix << endl;

    for (int i = 0; i < str.size(); ++i)
        printPermutations(str.substr(0, i) + str.substr(i + 1), prefix + str[i]);
}

// To - Do: Does not work for all cases. Use a set instead.
void printPermutationsWithoutDuplicates(string str, string prefix)
{
    if (str.size() == 0)
        cout << prefix << endl;

    bool visited[26] = {false};

    for (int i = 0; i < str.size(); ++i)
    {
        int index = str[i] - 'a';
        if (!visited[index])
            printPermutations(str.substr(0, i) + str.substr(i + 1), prefix + str[i]);
        visited[index] = true;
    }
}

int main()
{
    printPermutations("abc", "");
    cout << endl;
    printPermutationsWithoutDuplicates("aab", "");
    return 0;
}