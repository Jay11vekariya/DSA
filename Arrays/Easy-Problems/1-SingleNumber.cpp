/* 
    136. [Single Number]

    You have given an array in which all elements repeats twice except one element which is single, so find that one element. 
    e.g - {4, 1, 3, 1, 3} then output must be 4 
*/

#include <iostream>
#include <vector>
using namespace std;

// Brute-Force Approach  [Time-Complexity : O(n*n)]
void print_Single(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        bool isSingle = true;
        for (int j = 0; j < vec.size(); j++)
        {
            if (i != j && vec[i] == vec[j])
            {
                isSingle = false;
            }
        }
        if (isSingle)
        {
            cout << vec[i] << " ";
        }
    }
}

// Optimal Approach [Time-Complexity : O(n)]
void print_Single2(vector<int> &vec)
{
    int ans = 0;
    for (int val : vec)
    {
        ans = ans ^ val;
    }
    cout << ans << " ";
}

/*
    Why XOR works:

    We don't need nested loops because XOR can cancel out duplicate
    numbers.

    Important XOR properties:
        1. x ^ x = 0       → Same numbers cancel each other
        2. x ^ 0 = x       → XOR with 0 gives the same number
        3. XOR is commutative and associative, so the order doesn't matter

    Example:
        vec = {4, 1, 3, 1, 3}

        ans = 4 ^ 1 ^ 3 ^ 1 ^ 3

        Rearrange:
        ans = 4 ^ (1 ^ 1) ^ (3 ^ 3)

        Since:
        1 ^ 1 = 0
        3 ^ 3 = 0

        Therefore:
        ans = 4 ^ 0 ^ 0
        ans = 4

    So, the single element is 4.

    Time Complexity  : O(n)
    Space Complexity : O(1)

    Note:
    This approach works only when every element appears exactly twice
    except one element that appears exactly once.
*/

int main()
{

    vector<int> vec = {4, 1, 3, 1, 3};
    print_Single(vec);
    print_Single2(vec);

    return 0;
}
