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


int main()
{
    vector<int> nums = {2, 5, 6, 7};

    vector<int> ans = pairSum(nums, 11);

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
