#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int maxSubarray4(vector<int>& nums)
{
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        // Add current element to running sum
        currSum += nums[i];

        // Store maximum sum before possibly resetting currSum
        maxSum = max(maxSum, currSum);

        // Negative sum will not help future subarrays
        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Sum: " << maxSubarray4(nums);

    return 0;
}

/*
    Kadane's Algorithm - Maximum Subarray Sum

    Purpose:
    Find the maximum sum of a contiguous subarray efficiently.

    Main Idea:
    Keep a running sum (currSum) while traversing the array.

    We Maintain two variables:
        i) currSum -> sum of current subarray.
        ii) maxSum -> maximum subrray sum found so far.

    If currSum becomes negative, we discard it by resetting it
    to 0 because a negative sum will only decrease the sum of
    any future subarray.

    Approach:
    1. Initialize:
           currSum = 0
           maxSum  = INT_MIN

    2. Traverse each element of the array.

    3. Add the current element to currSum:
           currSum += nums[i]

    4. Update maxSum:
           maxSum = max(maxSum, currSum)

       This must be done BEFORE resetting currSum so that
       arrays containing only negative numbers are handled correctly.

    5. If currSum becomes negative:
           currSum = 0

       This means we discard the current subarray and start
       a new subarray from the next element.

    Why reset a negative currSum?
    -----------------------------
    Suppose:
        currSum = -5
        next element = 10

    Keeping previous sum:
        -5 + 10 = 5

    Starting fresh:
        10

    Since 10 > 5, carrying a negative sum can never help us
    get a larger sum in the future.

    Example:
        nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}

        currSum    maxSum
        ----------------
          -2         -2    -> reset currSum = 0
           1          1
          -2          1    -> reset currSum = 0
           4          4
           3          4
           5          5
           6          6
           1          6
           5          6

        Maximum subarray = {4, -1, 2, 1}
        Maximum sum      = 6

    Time Complexity  : O(n)
        The array is traversed only once.

    Space Complexity : O(1)
        Only currSum and maxSum are used.
*/