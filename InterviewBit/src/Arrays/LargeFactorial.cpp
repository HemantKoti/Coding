/*
 * LargeFactorial.cpp
 *
 *  Created on: Sep 21, 2020
 *      Author: kotih
 */

#include "../../include/interviewbit.h"

#define MAX 500

void multiply(int x, int result[], int &size)
{
    int carry = 0;
    for (int i = 0; i < size; i++)
    {
        int prod = result[i] * x + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry)
    {
        result[size] = (carry % 10);
        carry = carry / 10;
        size++;
    }
}

string largeFactorial(int A)
{
    int result[MAX];
    result[0] = 1;
    int size = 1;

    for (int i = 2; i <= A; i++)
        multiply(i, result, size);

    string str = "";
    for (int i = size - 1; i >= 0; i--)
    {
        str += to_string(result[i]);
    }

    return str;
}
