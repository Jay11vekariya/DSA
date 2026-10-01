/*
    169. [Majority Element]

    Given an array nums of size n, return the majority element.
    The majority element is the element that appears more than ⌊n / 2⌋ times.
    You may assume that the majority element always exists in the array.

    Example :
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Better Approach
int majorityElement(vector<int> nums)
{
    int n = nums.size();
    int freq = 1;

    sort(nums.begin(), nums.end()); // O(n log n)

    for (int i = 1; i < n; i++) // O(n)
    {
        if (nums[i] == nums[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
        }

        if (freq > n / 2)
        {
            return nums[i];
        }
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
    Sorting Approach for Majority Element:

    A majority element is an element that appears more than n/2 times
    in the array.

    Approach:
    1. Sort the array so that all equal elements come together.

    2. Initialize 'freq = 1' because the current element itself
       is counted once.

    3. Traverse the sorted array from index 1.

    4. Compare the current element with the previous element:
       - If nums[i] == nums[i - 1], increase freq.
       - Otherwise, reset freq to 1 because a new element has started.

    5. If freq becomes greater than n/2, return nums[i]
       because it is the majority element.

    Example:
        nums = {2, 1, 2, 2, 3, 2, 2}

        After sorting:
        nums = {1, 2, 2, 2, 2, 2, 3}

        n = 7
        n/2 = 3

        While traversing:
            1 -> freq = 1
            2 -> freq = 1
            2 -> freq = 2
            2 -> freq = 3
            2 -> freq = 4

        Since:
            freq > n/2
            4 > 3

        Therefore, 2 is the majority element.

    If no majority element exists, return -1.

    Time Complexity:
        Sorting   = O(n log n)
        Traversal = O(n)

        Total = O(n log n) + O(n)
              = O(n log n)

    Space Complexity:
        O(n) here because 'nums' is passed by value, so a copy of
        the vector is created.

        Note: If nums were passed by reference and sorted in-place,
        no vector copy would be created.
*/