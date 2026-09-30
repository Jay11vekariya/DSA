#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    // Store the size of the input array
    int n = nums.size();

    // Stores the final product except self for each index
    vector<int> answer(n, 1);

    // prefix[i] stores the product of all elements before index i
    vector<int> prefix(n, 1);

    // suffix[i] stores the product of all elements after index i
    vector<int> suffix(n, 1);

    // Build the prefix product array from left to right
    // Start from index 1 because there is nothing before index 0
    for (int i = 1; i < n; i++)
    {
        // Previous prefix product * previous element
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // Build the suffix product array from right to left
    // Start from n-2 because there is nothing after the last index
    for (int i = n - 2; i >= 0; i--)
    {
        // Next suffix product * next element
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Product except nums[i] =
    // product of elements before i * product of elements after i
    for (int i = 0; i < n; i++)
    {
        answer[i] = prefix[i] * suffix[i];
    }

    // Return the final result
    return answer;
}

int main()
{
    // Input array
    vector<int> nums = {1, 2, 3, 4};

    // Calculate product of array except self
    vector<int> answer = productExceptSelf(nums);

    // Print the answer
    for (int elem : answer)
    {
        cout << elem << "\n";
    }

    return 0;
}

/*
    Prefix & Suffix Approach - Product of Array Except Self

    Purpose:
    For every index i, find the product of all elements except nums[i]
    without using division.

    Main Idea:
    Instead of checking every other element for each index, divide the
    required product into two parts:

        answer[i] = product before i * product after i
                  = prefix[i] * suffix[i]

    Prefix Array:
        prefix[i] stores the product of all elements BEFORE index i.

        nums   = {1, 2, 3, 4}
        prefix = {1, 1, 2, 6}

        prefix[0] = 1                  // nothing before index 0
        prefix[1] = 1
        prefix[2] = 1 * 2 = 2
        prefix[3] = 1 * 2 * 3 = 6

        Formula:
            prefix[i] = prefix[i - 1] * nums[i - 1]

    Suffix Array:
        suffix[i] stores the product of all elements AFTER index i.

        nums   = {1, 2, 3, 4}
        suffix = {24, 12, 4, 1}

        suffix[3] = 1                  // nothing after last index
        suffix[2] = 4
        suffix[1] = 3 * 4 = 12
        suffix[0] = 2 * 3 * 4 = 24

        Formula:
            suffix[i] = suffix[i + 1] * nums[i + 1]

    Final Answer:
        answer[i] = prefix[i] * suffix[i]

        index        0    1    2    3
        nums         1    2    3    4
        prefix       1    1    2    6
        suffix      24   12    4    1
        --------------------------------
        answer      24   12    8    6

    Why initialize prefix and suffix with 1?
        1 is the identity value for multiplication.

        There is nothing before the first element,
        so prefix[0] = 1.

        There is nothing after the last element,
        so suffix[n - 1] = 1.

    Why is this better than brute force?
        Brute Force:
            For every index, traverse the entire array.
            Time Complexity = O(n^2)

        Prefix + Suffix:
            Build prefix  -> O(n)
            Build suffix  -> O(n)
            Build answer  -> O(n)

            Total = O(n)

    Time Complexity  : O(n)

    Space Complexity : O(n)
        prefix and suffix arrays require extra space.

    Note:
        This approach can be optimized further to O(1) auxiliary
        space by using the answer array for prefix products and
        a variable for the running suffix product.
*/