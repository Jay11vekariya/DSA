#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
// Time Complexity: O(N), we check for every number from 1 to N.
void PrintDivisor(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }
}

// OPTIMAL APPROACH
// Time Complexity: O(sqrt(N)), we check for every number between 1 and sqaure root of N.
// Space Complexity: O(2*sqrt(N)), extra space used for storing divisors.
void printDivisor(int n)
{
    vector<int> vec;
    for (int i = 1; i <= sqrt(n); i++) // Alternate condition : (i*i <= n) instead of (i <= sqrt(n)).
    {
        if (n % i == 0)
        {
            vec.emplace_back(i);
            if ((n / i) != i)
                vec.emplace_back(n / i);
        }
    }
    sort(vec.begin(), vec.end());
    for (auto item : vec)
        cout << item << " ";
}

int main()
{
    int n = 36;
    PrintDivisor(n);
    cout << endl;
    printDivisor(n);
    return 0;
}