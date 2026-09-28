#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    // 'start' selects the starting index of the subarray
    for (int start = 0; start < nums.size(); start++)
    {
        // 'end' selects the ending index of the subarray
        for (int end = start; end < nums.size(); end++)
        {
            // Print elements from start to end
            for (int i = start; i <= end; i++)
            {
                cout << nums[i] << " ";
            }

            cout << endl;
        }
    }

    return 0;
}

/*
    Approach to Print All Subarrays:

    A subarray is a continuous part of an array.

    We use three nested loops:

    1. 'start' selects the starting index of the subarray.

    2. 'end' selects the ending index of the subarray.
       It starts from 'start' because the ending index
       cannot come before the starting index.

    3. 'i' traverses from start to end and prints
       all elements of the selected subarray.

    Example:
        nums = {1, 2, 3}

        start = 0:
            end = 0 -> {1}
            end = 1 -> {1, 2}
            end = 2 -> {1, 2, 3}

        start = 1:
            end = 1 -> {2}
            end = 2 -> {2, 3}

        start = 2:
            end = 2 -> {3}

    Number of subarrays = n(n + 1) / 2

    Time Complexity  : O(n^3)  // because we also print each subarray
    Space Complexity : O(1)
*/