#include <bits/stdc++.h>
using namespace std;

int DigitSum(int n)
{
    int lastDigit = 0;
    int digitSum = 0;
    while (n > 0)
    {
        lastDigit = n % 10;
        digitSum += lastDigit;
        n = n / 10;
    }
    return digitSum;
}

int main()
{
    cout << "Sum of= " << DigitSum(123);
    return 0;
}
