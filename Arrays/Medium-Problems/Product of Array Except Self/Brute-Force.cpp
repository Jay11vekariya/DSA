/*

    238. [Product of Array Except Self]

    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the 
    elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
    You must write an algorithm that runs in O(n) time and without using the division operation.

    Example 1:
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

*/

#include <iostream>
#include <vector>
using namespace std;

// Brute-Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n) for the answer array
vector<int> productExceptSelf(vector<int> &nums)
{
    // Stores the final product for every index
    vector<int> answer;

    // Stores the product of all elements except the current element
    int ans = 1;

    // Select each element one by one
    for (int i = 0; i < nums.size(); i++)
    {
        // Traverse the entire array for the current index i
        for (int j = 0; j < nums.size(); j++)
        {
            // Skip the current element nums[i]
            if (i != j)
                ans = ans * nums[j];
        }

        // Store the product of all elements except nums[i]
        answer.push_back(ans);

        // Reset product for the next index
        ans = 1;
    }

    // Return the final answer array
    return answer;
}

int main()
{
    // Input array
    vector<int> nums = {1, 2, 3, 4};

    // Find product of array except self
    vector<int> answer = productExceptSelf(nums);

    // Print the resulting array
    for (int elem : answer)
    {
        cout << elem << "\n";
    }

    return 0;
}

/*
    Brute-Force Approach - Product of Array Except Self

    Purpose:
    For every index i, calculate the product of all elements
    in the array except nums[i].

    Approach:

    1. Traverse each element using the outer loop.

    2. For every index i, traverse the entire array again
       using the inner loop.

    3. If i != j:
           Multiply nums[j] with ans.

       This skips the current element nums[i].

    4. After the inner loop finishes:
           answer.push_back(ans)

       Store the product for the current index.

    5. Reset:
           ans = 1

       so that the product for the next index starts fresh.

    Example:
        nums = {1, 2, 3, 4}

        i = 0:
            Skip nums[0]
            ans = 2 * 3 * 4 = 24

        i = 1:
            Skip nums[1]
            ans = 1 * 3 * 4 = 12

        i = 2:
            Skip nums[2]
            ans = 1 * 2 * 4 = 8

        i = 3:
            Skip nums[3]
            ans = 1 * 2 * 3 = 6

        answer = {24, 12, 8, 6}

    Why initialize ans = 1?
        Because 1 is the identity value for multiplication.
        Starting with 0 would make every product equal to 0.

    Time Complexity  : O(n^2)
        For every element, we traverse the entire array.

    Space Complexity : O(n)
        The answer vector stores n elements.

        Auxiliary Space = O(1)
        if the required output array is not counted.
*/