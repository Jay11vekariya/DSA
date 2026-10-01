#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // Optimize calculation:
        // int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    // For Binary Search Array must be sorted 
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(int);
    int target = 30;

    if (BinarySearch(arr, size, target) == -1)
        cout << "Number not found!" << endl;
    else
        cout << target << " found at index: " << BinarySearch(arr, size, target) << endl;

    return 0;
}

/*
    [Optimized Mid Calculation]:

    Instead of:
    int mid = (low + high) / 2;

    We use:
    int mid = low + (high - low) / 2;

    Reason:
    If low and high are very large integers, adding them first (low + high)
    may exceed the maximum range of int and cause integer overflow.

    Example:
    low  = 1,500,000,000
    high = 2,000,000,000

    (low + high) = 3,500,000,000  -> exceeds INT_MAX (2,147,483,647)

    But:
    high - low = 500,000,000
    (high - low) / 2 = 250,000,000
    mid = low + 250,000,000
        = 1,750,000,000

    Therefore, low + (high - low) / 2 gives the same midpoint
    while reducing the risk of integer overflow.
*/