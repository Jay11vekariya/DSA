#include <bits/stdc++.h>
using namespace std;

int DecimalToBinary(int n)
{
    int pow = 1;
    int ans = 0;

    while (n > 0)
    {
        int rem = n % 2;
        n = n / 2;

        ans = ans + rem * pow;
        pow *= 10;
    }

    return ans;
}
int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << DecimalToBinary(i) << endl;
    }
    
    return 0;
}
