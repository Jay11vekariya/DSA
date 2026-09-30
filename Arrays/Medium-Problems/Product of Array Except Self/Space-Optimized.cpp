#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    // Store the size of the input array
    int n = nums.size();

    // answer array will first store prefix products
    // and later store the final result
    vector<int> answer(n, 1);

    // Build prefix products directly inside the answer array
    // answer[i] = product of all elements before index i
    for (int i = 1; i < n; i++)
    {
        // Previous prefix product * previous element
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Stores the product of all elements to the right
    // Start with 1 because there is nothing after the last element
    int suffix = 1;

    // Traverse from right to left to calculate suffix products
    for (int i = n - 2; i >= 0; i--)
    {
        // Include the next element in the running suffix product
        suffix = suffix * nums[i + 1];

        // Final answer = prefix product * suffix product
        answer[i] = answer[i] * suffix;
    }

    // Return the final product except self array
    return answer;
}

int main()
{
    // Input array
    vector<int> nums = {1, 2, 3, 4};

    // Calculate product of array except self
    vector<int> answer = productExceptSelf(nums);

    // Print the resulting array
    for (int elem : answer)
    {
        cout << elem << "\n";
    }

    return 0;
}


/*
    Previous approach:

    prefix[]  → O(n)
    suffix[]  → O(n)
    answer[]  → output

    Now:

    answer[]  → stores prefix first, then final answer
    suffix    → one variable

    Time Complexity      : O(n)
    Auxiliary Space      : O(1)
    Output Space         : O(n)
*/