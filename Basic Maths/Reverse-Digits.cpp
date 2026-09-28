#include <bits/stdc++.h>
using namespace std;

int ReverseDigit(int n)
{
    int lastDigit = 0;
    int reversedDigits = 0;
    while (n > 0)
    {
        lastDigit = n % 10;
        n = n / 10;
        reversedDigits = reversedDigits * 10 + lastDigit;
    }
    return reversedDigits;
}

int main()
{
    cout << ReverseDigit(123);
    return 0;
}
