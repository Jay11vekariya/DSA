#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (target == arr[i])
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(int);
    int target = 30;
    
    if (linearSearch(arr, size, target) == -1)
        cout << "Number not found!" << endl;
    else
        cout << target << " found at index: " << linearSearch(arr, size, target) << endl;

    return 0;
}
