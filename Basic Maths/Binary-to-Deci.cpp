#include <bits/stdc++.h>
using namespace std;

int BinaryToDecimal(int n)
{
    int power = 0;
    int ans = 0;

    while (n > 0)
    {
        int lastDigit = n % 2;
        n = n / 10;
        ans = ans + (lastDigit * pow(2, power));
        power++;
    }

    return ans;
}

int main()
{
    cout << BinaryToDecimal(10110) << endl;
    return 0;
}