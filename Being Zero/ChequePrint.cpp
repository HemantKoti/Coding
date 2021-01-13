#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

char *numbers[] = {"Zero", "One", "Two", "Three", "Four",
                   "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                   "Twelve", "Thirteen", "Fourteen", "Fifteen",
                   "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};

char *tens[] = {"", "Ten", "Twenty", "Thirty", "Forty",
                "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};

void printTwoDigitNumbers(long n)
{
    int rem;
    assert(n < 100);

    if (n < 20)
        cout << numbers[n];
    else
    {
        rem = n % 10;
        n = n / 10;
        cout << tens[n] << " " << numbers[rem];
    }
}

void numToWords(long int n)
{
    while (n != 0)
    {
        if (n < 0)
        {
            cout << " minus ";
            n = 0 - n;
        }

        if (n >= 100000)
        {
            printTwoDigitNumbers(n / 100000);
            cout << " lakh ";
            n = n % 100000;
        }
        else if (n >= 1000)
        {
            printTwoDigitNumbers(n / 1000);
            cout << " thousand ";
            n = n % 1000;
        }
        else if (n >= 100)
        {
            printTwoDigitNumbers(n / 100);
            cout << " hundred ";
            n = n % 100;
        }
        else if (n >= 10)
        {
            printTwoDigitNumbers(n);
            break;
        }
    }
}

int main()
{
    long int num;
    cout << "Enter any number: ";
    cin >> num;
    numToWords(num);
    return 0;
}
