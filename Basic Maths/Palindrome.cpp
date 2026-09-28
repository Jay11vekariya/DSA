#include <bits/stdc++.h>
using namespace std;

int ReversedDigit(int n)
{
    int lastDigit = 0;
    int reversedDigits = 0;
    while (n > 0)
    {
        lastDigit = n % 10;
        n /= 10;
        reversedDigits = reversedDigits * 10 + lastDigit;
    }
    return reversedDigits;
}

int main()
{
    int n = 121;
    if (n == ReversedDigit(n))
        cout << n << " is Palindrome number.";
    else
        cout << n << " is not Palindrome number.";
    return 0;
}
