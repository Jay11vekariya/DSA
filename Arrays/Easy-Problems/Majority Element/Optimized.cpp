/*
    [Majority Element]

    Given an array nums of size n, return the majority element.
    The majority element is the element that appears more than ⌊n / 2⌋ times.
    You may assume that the majority element always exists in the array.

    Example :
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2
*/

#include <iostream>
#include <vector>
using namespace std;

// Optimal Approach
// ||---------- Moore's Voting Algorithm -------------||
int majorityElement(vector<int> nums)
{
    int freq = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (freq == 0)
            ans = nums[i];

        if (nums[i] == ans)
            freq++;
        else
            freq--;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(nums) << endl;

    return 0;
}

/*
    Moore's Voting Algorithm (Boyer-Moore) for Majority Element:

    The idea is to find the majority element by cancelling out
    occurrences of different elements.

    We maintain two variables:
        ans  -> current candidate for majority element
        freq -> vote/count of the current candidate

    Approach:
    1. Traverse the array from left to right.

    2. If freq == 0:
       - Choose the current element as the new candidate (ans).

    3. Compare the current element with the candidate:
       - If nums[i] == ans, increase freq.
       - Otherwise, decrease freq.

    4. When freq becomes 0, it means the current candidate's
       occurrences have been cancelled by different elements.
       So, the next element can become the new candidate.

    Example:
        nums = {2, 2, 1, 1, 1, 2, 2}

        Element     Candidate(ans)     freq
        -----------------------------------
           2              2             1
           2              2             2
           1              2             1
           1              2             0
           1              1             1
           2              1             0
           2              2             1

        Final candidate = 2

        Therefore, 2 is the majority element.

    Why it works:
        Since the majority element appears more than n/2 times,
        even after cancelling it with all different elements,
        the majority element will remain as the final candidate.

    Time Complexity  : O(n)
        - The array is traversed only once.

    Space Complexity : O(1)
        - Only 'freq' and 'ans' are used.

    Note:
        This code assumes that a majority element always exists.
        If majority is not guaranteed, we need another pass to
        verify that 'ans' actually appears more than n/2 times.
*/
