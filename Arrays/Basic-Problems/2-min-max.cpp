#include <bits/stdc++.h>
using namespace std;

// INT_MIN = -INFINITY (smallest number ever)
// INT_MAX = +INFINITY (largest number ever)

void find_largest(int arr[], int size)
{
    int largest = INT_MIN;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
            index = i;
        }

        // largest = max(arr[i], largest);  --> alternate of if{...}
    }
    cout << "Largest is: " << largest << " at index: " << index << endl;
}

void find_smallest(int arr[], int size)
{
    int smallest = INT_MAX;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (smallest > arr[i])
        {
            smallest = arr[i];
            index = i;
        }

        // smallest = min(arr[i], smallest);  --> alternate of if{...}
    }

    cout << "smallest is: " << smallest << " at index: " << index << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(int);

    find_largest(arr, size);
    find_smallest(arr, size);
    return 0;
}
