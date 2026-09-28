#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

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
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(int);
    int target = 30;

    if (BinarySearch(arr, size, target) == -1)
        cout << "Number not found!" << endl;
    else
        cout << target << " found at index: " << BinarySearch(arr, size, target) << endl;

    return 0;
}
