
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int maxSubarray1(vector<int>& nums)
{
    int maxSum = INT_MIN;

    // Select starting index
    for (int start = 0; start < nums.size(); start++)
    {
        // Select ending index
        for (int end = start; end < nums.size(); end++)
        {
            int currSum = 0;

            // Calculate sum from start to end
            for (int i = start; i <= end; i++)
            {
                currSum += nums[i];
            }

            // Store maximum sum found so far
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Sum: " << maxSubarray1(nums);

    return 0;
}

/*
    Brute-Force Approach for Maximum Subarray Sum:

    The idea is to generate every possible contiguous subarray,
    calculate its sum, and keep track of the maximum sum found.

    We use three nested loops:

    1. 'start' selects the starting index of the subarray.

    2. 'end' selects the ending index of the subarray.
       It starts from 'start' because the ending index cannot
       come before the starting index.

    3. 'i' traverses from start to end and calculates the sum
       of the current subarray.

    After calculating the sum of each subarray:
        - Compare currSum with maxSum.
        - Store the larger value in maxSum.
        - Reset currSum to 0 for the next subarray.

    Example:
        nums = {-2, 1, -3, 4}

        Some subarrays:
        {-2}          -> sum = -2
        {-2, 1}       -> sum = -1
        {-2, 1, -3}   -> sum = -4
        {1}           -> sum = 1
        {1, -3}       -> sum = -2
        {4}           -> sum = 4

        Maximum Sum = 4

    Time Complexity  : O(n^3)
    Space Complexity : O(1)
*/

