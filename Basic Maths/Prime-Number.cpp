#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
bool IsPrime(int n)
{
    if (n <= 1)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

// BRUTE FORCE APPROACH
// Time Complexity: O(N), as we iterate from 1 to N performing constant-time operation for each iteration.
// Space Complexity : O(1), as the space used by the algorithm does not increase with the size of the input.
bool checkPrime(int n)
{
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        // If n is divisible by i without any remainder.
        if (n % i == 0)
            count++; // Increment the counter.
    }

    // If the number of factors is exactly 2 (1 and the number itself), it's prime.
    if (count == 2)
        return true;

    // If the number of factors is not 2, it's not prime.
    else
        return false;
}

// OPTIMAL APPROACH
// Time Complexity: O(sqrt(N)), as The loop iterates up to the square root of n performing constant time operations at each step.
// Space Complexity : O(1), as the space complexity remains constant and independent of the input size. Only a fixed amount of memory is required to store the integer variables.
bool IsPrime2(int n)
{
    int FactorCount = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            FactorCount++;
            if ((n / i) != i)
                FactorCount++;
        }
    }

    if (FactorCount == 2)
        return true;
    else
        return false;
}

void print_N_primes(int n)
{
    int count = 0;
    int num = 2;

    while (count < n)
    {
        if (IsPrime2(num))
        {
            cout << num << " ";
            count++;
        }
        num++;
    }
}

int main()
{
    int n = 7;
    if (IsPrime2(n))
        cout << n << " is prime number.";
    else
        cout << n << " is not prime number.";

    cout << endl;
    print_N_primes(n);
    return 0;
}
