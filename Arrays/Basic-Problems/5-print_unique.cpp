#include <bits/stdc++.h>
using namespace std;

void print_unique(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool isUnique = true;
        for (int j = 0; j < size; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                isUnique = false;
                break;
            }
        }

        if (isUnique)
            cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1,42,4,5,2,1,3,5,2,1};
    int size = sizeof(arr) / sizeof(int);

    print_unique(arr, size);
   
    return 0;
}
