#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int maxSubarray3(vector<int>& nums)
{
    int n = nums.size();
    int maxSum = INT_MIN;

    // prefix[i] stores sum from index 0 to i
    vector<int> prefix(n);

    // Build prefix sum array
    prefix[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int currSum;

            if (start == 0)
            {
                // Sum from index 0 to end
                currSum = prefix[end];
            }
            else
            {
                // Remove the sum before 'start'
                currSum = prefix[end] - prefix[start - 1];
            }

            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Sum: " << maxSubarray3(nums);

    return 0;
}

/*
    Prefix Sum Approach for Maximum Subarray Sum:

    The idea is to first create a prefix array where each index stores
    the sum of all elements from index 0 up to that index.

    Example:
        nums   = {3, -4, 5, 4, -1}

        prefix[0] = 3
        prefix[1] = 3 + (-4)       = -1
        prefix[2] = 3 + (-4) + 5   = 4
        prefix[3] = 3 + (-4) + 5 + 4 = 8
        prefix[4] = 3 + (-4) + 5 + 4 + (-1) = 7

        prefix = {3, -1, 4, 8, 7}

    Meaning:
        prefix[i] = sum of elements from index 0 to i.

    After creating the prefix array, we generate every possible
    subarray using two loops:

        1. 'start' selects the starting index.
        2. 'end' selects the ending index.

    Instead of traversing from start to end to calculate the sum,
    we use the prefix array.

    Formula:

        If start == 0:
            currSum = prefix[end]

        Otherwise:
            currSum = prefix[end] - prefix[start - 1]

    Why does this formula work?

        prefix[end]
        contains the sum of elements from index 0 to end.

        prefix[start - 1]
        contains the sum of elements before 'start'.

        Therefore, subtracting them leaves only the sum of elements
        from 'start' to 'end'.

    Example:

        nums   = {3, -4, 5, 4, -1}
        prefix = {3, -1, 4, 8, 7}

        Suppose:
            start = 2
            end   = 4

        Required subarray:
            {5, 4, -1}

        currSum = prefix[4] - prefix[1]
                = 7 - (-1)
                = 8

        Therefore:
            5 + 4 + (-1) = 8

    Special Case:

        When start == 0, we cannot use:

            prefix[start - 1]

        because:
            start - 1 = -1

        and prefix[-1] is an invalid array index.

        Therefore:
            currSum = prefix[end]

    After calculating the sum of each subarray, compare currSum
    with maxSum and keep the maximum value.

    Time Complexity:
        Creating prefix array = O(n)
        Checking all subarrays = O(n^2)

        O(n) + O(n^2) = O(n^2)

    Space Complexity:
        O(n) because an additional prefix array of size n is used.
*/