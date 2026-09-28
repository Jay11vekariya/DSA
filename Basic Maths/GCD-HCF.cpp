#include <bits/stdc++.h>
using namespace std;

// GCD (greatest common divisor) | HCF (highest common factor)

// BRUTE FORCE APPROACH
// Time Complexity: O(min(a, b)) | Space Complexity: O(1)
int findGCD(int a, int b)
{
    int gcd = 1;
    for (int i = 1; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

// This reverse approach is efficient for some cases not for all.
// Time Complexity: O(min(a, b)) | Space Complexity: O(1)
int findHCF(int a, int b)
{
    int gcd = 1;
    for (int i = min(a, b); i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break;
        }
    }
    return gcd;
}

// OPTIMAL APPROACH (Euclidean Algorithm)
// Time Complexity: O(log(min(a, b))) | Space Complexity: O(1)
int find_HCF_GCD(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    if (a == 0)
        return b;

    return a;
}

int main()
{
    int a = 12, b = 20;
    cout << "GCD of " << a << " " << b << ": " << findGCD(a, b) << endl;
    cout << "HCF of " << a << " " << b << ": " << findHCF(a, b) << endl;
    cout << "GCD/HCF of " << a << " " << b << ": " << find_HCF_GCD(a, b) << endl;
    return 0;
}
