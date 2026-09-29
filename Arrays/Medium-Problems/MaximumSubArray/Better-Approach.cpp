#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int maxSubarray(vector<int>& nums)
{
    int maxSum = INT_MIN;

    // Select starting index
    for (int start = 0; start < nums.size(); start++)
    {
        // New group of subarrays starts here
        int currSum = 0;

        // Extend subarray from start to end
        for (int end = start; end < nums.size(); end++)
        {
            // Add only the newly included element
            currSum += nums[end];

            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Sum: " << maxSubarray(nums);

    return 0;
}

/*
    Better Approach for Maximum Subarray Sum:

    The idea is to generate all possible subarrays and calculate their
    sums efficiently by reusing the sum of the previous subarray.

    We use two nested loops:

    1. 'start' selects the starting index of the subarray.

    2. 'end' moves from 'start' to the end of the array.
       Instead of using a third loop to calculate the sum from
       start to end every time, we keep adding nums[end] to currSum.

       currSum += nums[end];

    3. After adding each element, compare currSum with maxSum
       and store the larger value.

    4. When 'start' changes, reset currSum to 0 because we are
       starting a new group of subarrays.

    Example:
        nums = {3, -4, 5, 4}

        start = 0:
            {3}             -> currSum = 3
            {3, -4}         -> currSum = -1
            {3, -4, 5}      -> currSum = 4
            {3, -4, 5, 4}   -> currSum = 8

        start = 1:
            {-4}            -> currSum = -4
            {-4, 5}         -> currSum = 1
            {-4, 5, 4}      -> currSum = 5

        start = 2:
            {5}             -> currSum = 5
            {5, 4}          -> currSum = 9

        start = 3:
            {4}             -> currSum = 4

        Maximum Sum = 9

    Time Complexity  : O(n^2)
    Space Complexity : O(1)
*/