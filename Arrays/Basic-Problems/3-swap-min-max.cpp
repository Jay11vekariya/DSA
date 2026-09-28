#include <bits/stdc++.h>
using namespace std;

void swap_min_max(int arr[], int size)
{
    int max = INT_MIN, min = INT_MAX, maxIndex = 0, minIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            maxIndex = i;
        }

        if (min > arr[i])
        {
            min = arr[i];
            minIndex = i;
        }
    }
    swap(arr[maxIndex], arr[minIndex]);
}

int main()
{
    int arr[] = {11, 22, 33, 44, 55};
    int size = sizeof(arr) / sizeof(int);

    swap_min_max(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}