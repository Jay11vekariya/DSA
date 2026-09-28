#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

//------ nCr = n! / r! * (n-r)! ------//
int calculate_nCr(int n, int r)
{
    int C = (factorial(n)) / ((factorial(r)) * (factorial(n - r)));
    return C;
}

int main()
{
    int n = 8, r = 2;
    cout << calculate_nCr(n, r);
    return 0;
}
