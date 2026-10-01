#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int target, int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] < target)
            return BinarySearch(arr, target, mid + 1, high);
        else if (arr[mid] > target)
            return BinarySearch(arr, target, low, mid - 1);
        else
            return mid;
    }

    return -1;
}

int main()
{
    int arr[] = {-1, 0, 3, 7, 12, 18, 34, 59};
    int size = sizeof(arr) / sizeof(int);
    int target = 18;

    cout << BinarySearch(arr, target, 0, size - 1);

    return 0;
}
