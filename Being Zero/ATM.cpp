#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

void amountToNotes(long int n)
{
    int noh, noth, nof;
    noth = noh = nof = 0;
    assert(n % 100 == 0);
    while (n != 0)
    {
        if (n >= 1000)
        {
            noth = noth + n / 1000;
            n = n - noth * 1000;
        }
        else if (n >= 500 && n < 1000)
        {
            nof = n / 500;
            n = n - nof * 500;
        }
        else
        {
            noh = n / 100;
            n = n - noh * 100;
        }
    }

    printf(" \n 1000's : %d \n 500's : %d \n 100's : %d \n ", noth, nof, noh);
}

// ../Materials/CPS - 2/Problem 12 - ATM note count.pdf
int main()
{
    long int num;
    printf("\n Enter the amount \n");
    scanf("%ld", &num);
    amountToNotes(num);
    return 0;
}
