#include <iostream>
#include <vector>
#include <string>

using namespace std;

void permutationWithCaseChange(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }

    string output1, output2;
    output1 = output + " " + input[0];
    output2 = output + input[0];
    input.erase(input.begin() + 0);
    permutationWithCaseChange(input, output1);
    permutationWithCaseChange(input, output2);
}

int main()
{
    string input("Hemant");
    string output;
    output += input[0];

    permutationWithCaseChange(input.substr(1), output);

    return 0;
}