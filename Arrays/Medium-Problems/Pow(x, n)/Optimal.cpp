/*  
    50. [Pow(x, n)]
    
    Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
    
    Example:
    Input: x = 2.00000, n = 10
    Output: 1024.00000
*/

#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    // Store n in long long because -INT_MIN cannot fit in int
    long long binform = n;

    double ans = 1;

    // If power is negative:
    // x^(-n) = (1/x)^n
    if (binform < 0)
    {
        x = 1 / x;
        binform = -binform;
    }

    // Binary Exponentiation
    // Process the exponent using its binary representation
    while (binform > 0)
    {
        // If current exponent is odd,
        // include current x in the answer
        if (binform % 2 == 1)
        {
            ans = ans * x;
        }

        // Square the base for the next power
        x = x * x;

        // Divide exponent by 2
        binform = binform / 2;
    }

    return ans;
}

int main()
{
    cout << myPow(2, 10) << endl;

    return 0;
}

/*
    Binary Exponentiation (Fast Power):

    Purpose:
    Calculate x^n efficiently.

    Why use Binary Exponentiation?
    --------------------------------
    The normal approach multiplies x by itself n times.

        x^n = x * x * x * ... n times

    This takes O(n) time.

    Binary Exponentiation reduces the exponent by half in every
    iteration, so it calculates x^n in O(log n) time.

    ------------------------------------------------------------

    Main Idea:

    Every number can be represented in binary.

    Example:
        n = 10

        10 in binary = 1010

        10 = 8 + 2

        Therefore:

        x^10 = x^(8 + 2)
             = x^8 * x^2

    So instead of multiplying x 10 times, we only need the powers
    corresponding to the binary bits that are 1.

    ------------------------------------------------------------

    How does the code process the binary form of n?

    We do NOT explicitly convert n into binary.

    We use:

        binform % 2

    to check the rightmost binary bit.

        Remainder 1 -> current binary bit is 1
        Remainder 0 -> current binary bit is 0

    Then:

        binform /= 2

    removes the rightmost binary bit and moves to the next bit.

    Example for n = 10:

        Decimal     Binary     n % 2
          10         1010        0
           5          101        1
           2           10        0
           1            1        1

    So the bits are processed from right to left:
        0 -> 1 -> 0 -> 1

    ------------------------------------------------------------

    Working:

    We start with:
        ans = 1

    In every iteration:

    1. If binform is odd (current binary bit is 1):

           ans = ans * x

       because this power of x is required in the final answer.

    2. Square x:

           x = x * x

       This generates powers:

           x^1 -> x^2 -> x^4 -> x^8 -> x^16 ...

    3. Divide binform by 2:

           binform = binform / 2

       This moves to the next binary bit.

    ------------------------------------------------------------

    Example:
        x = 2, n = 10

        n = 10 = 1010 (binary)

        Required powers are:
            2^2 and 2^8

        Therefore:

            2^10 = 2^8 * 2^2
                 = 256 * 4
                 = 1024

        Dry Run:

        n       x       ans       Action
        ---------------------------------------
        10      2        1        even -> skip
         5      4        4        odd  -> ans *= x
         2     16        4        even -> skip
         1    256     1024        odd  -> ans *= x

        Final Answer = 1024

    ------------------------------------------------------------

    Negative Power:

    If n is negative:

        x^(-n) = (1/x)^n

    Example:

        2^-3 = (1/2)^3 = 1/8

    So we convert:

        x = 1/x
        n = -n

    ------------------------------------------------------------

    Why use long for binform?

    Integer.MIN_VALUE = -2147483648

    Its positive value 2147483648 cannot fit inside an int.

    Therefore, n is stored in a long before converting a negative
    exponent into a positive exponent.

    ------------------------------------------------------------

    Time Complexity  : O(log |n|)
        Because the exponent is divided by 2 in every iteration.

    Space Complexity : O(1)
        Only a few variables are used.
*/