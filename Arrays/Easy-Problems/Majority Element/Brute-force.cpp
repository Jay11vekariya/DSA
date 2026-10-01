#include <iostream>
#include <vector>
using namespace std;

// Brute-Force Approach
int majorityElement(vector<int> &nums)
{
    int freq = 0;
    int n = nums.size();

    for (int val : nums)
    {
        for (int elem : nums)
        {
            if (val == elem)
            {
                freq++;
            }
        }

        if (freq > n / 2)
            return val;
        else
            freq = 0;
    }
    return -1;
}


int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(nums) << endl;

    return 0;
}

/*
    Brute-Force Approach for Majority Element:

    A majority element is an element that appears more than n/2 times
    in the array, where n is the size of the array.

    Approach:
    1. Take each element 'val' from the array using the outer loop.

    2. Use the inner loop to compare 'val' with every element
       in the array.

    3. Whenever val == elem, increase 'freq' by 1.

    4. After checking the whole array:
       - If freq > n/2, then 'val' is the majority element,
         so return it.
       - Otherwise, reset freq to 0 and check the next element.

    Example:
        nums = {2, 2, 1, 1, 1, 2, 2}
        n = 7
        n/2 = 3

        For val = 2:
            2 appears 4 times

            freq = 4

            Since:
                4 > 7/2
                4 > 3

            Therefore, 2 is the majority element.

    If no element appears more than n/2 times, return -1.

    Time Complexity  : O(n^2)
        - Outer loop runs n times.
        - Inner loop runs n times for each outer iteration.

    Space Complexity : O(1)
        - Only a few variables are used.
*/
