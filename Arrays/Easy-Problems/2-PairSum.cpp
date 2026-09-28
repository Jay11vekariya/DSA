/*
    [Pair Sum]

    You are given a sorted array in ascending order of integers
    and a target value. Return the indices of the two numbers
    such that they add up to the target.
*/

#include <iostream>
#include <vector>
using namespace std;

// Brute-Force Approach
// Time Complexity: O(n^2) | Space Complexity: O(1) excluding the returned vector
vector<int> pairSum(vector<int> &nums, int target)
{
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }

    return ans;
}

// Optimal Approach -- Two Pointers Approach
vector<int> pairSum2(vector<int> &nums, int target)
{
    vector<int> ans;

    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        int sum = nums[i] + nums[j];

        if (sum > target)
        {
            j--;
        }
        else if (sum < target)
        {
            i++;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 5, 6, 7};

    vector<int> ans = pairSum2(nums, 11);

    if (ans.size() == 2)
    {
        cout << ans[0] << ", " << ans[1] << endl;
    }
    else
    {
        cout << "Pair not found." << endl;
    }

    return 0;
}

/*
    Two-Pointer Approach:

    Purpose:
    Find the indices of two elements in a sorted array whose
    sum is equal to the given target.

    Approach:
    - Place pointer i at the beginning of the array.
    - Place pointer j at the end of the array.
    - Calculate nums[i] + nums[j].

    If sum < target:
        Move i forward because we need a larger value.

    If sum > target:
        Move j backward because we need a smaller value.

    If sum == target:
        We found the pair, so return indices i and j.

    This approach works because the array is sorted.

    Example:
        nums = {2, 5, 6, 7}, target = 11

        2 + 7 = 9   < 11  -> i++
        5 + 7 = 12  > 11  -> j--
        5 + 6 = 11  == 11 -> Pair found

        Answer = {1, 2}

    Time Complexity  : O(n)
    Space Complexity : O(1)
*/