#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
// Time Complexity: O(1) | Space Complexity : O(1)
int CountDigits(int n)
{
    int digitCount = 0;
    int digit = 0;

    while (n > 0)
    {
        n /= 10;
        digitCount++;
    }

    return digitCount;
}

// OPTIMAL APPROACH
// Time Complexity: O(log10N + 1) | Space Complexity : O(1)
int countDigits(int n)
{

    int cnt = (int)(log10(n) + 1);
    return cnt;
}

int main()
{
    cout << CountDigits(3212) << endl;
    cout << countDigits(3212);
    return 0;
}
