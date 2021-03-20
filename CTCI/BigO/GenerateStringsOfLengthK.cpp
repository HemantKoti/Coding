#include <iostream>
#include <string>
#include <fstream>

#define NUMCHARS 26

using namespace std;

ofstream file;

char ithLetter(int i)
{
    return (char)(((int)'a') + i);
}

bool isInOrder(string s)
{
    for (int i = 1; i < s.size(); i++)
    {
        int prev = ithLetter(s[i - 1]), curr = ithLetter(s[i]);
        if (prev > curr)
            return false;
    }

    return true;
}

void printSortedStringsUtil(int remaining, string prefix)
{
    if (remaining == 0)
    {
        if (isInOrder(prefix))
            file << prefix << endl;
    }
    else
    {
        for (int i = 0; i < NUMCHARS; i++)
        {
            char c = ithLetter(i);
            printSortedStringsUtil(remaining - 1, prefix + c);
        }
    }
}

void printSortedStrings(int remaining)
{
    printSortedStringsUtil(remaining, "");
}

int main()
{

    file.open("C:/Users/kotih/Documents/Coding/Coding/CTCI/BigO/output.txt", ios_base::app | ios_base::out);
    printSortedStrings(5);
    file.close();
    return 0;
}