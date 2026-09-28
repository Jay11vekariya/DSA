#include <bits/stdc++.h>
using namespace std;

void print_intersection(int arr1[], int arr2[], int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        bool foundInArr2 = false;
        bool alreadyPrinted = false;

        // Check whether arr1[i] exists in arr2
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                foundInArr2 = true;
                break;
            }
        }

        // Check whether arr1[i] was already printed
        for (int j = 0; j < i; j++)
        {
            if (arr1[i] == arr1[j])
            {
                alreadyPrinted = true;
                break;
            }
        }

        if (foundInArr2 && !alreadyPrinted)
        {
            cout << arr1[i] << " ";
        }
    }
}

int main()
{
    int arr1[] = {1, 23, 36, 3, 3, 5, 11};
    int arr2[] = {3, 2, 11, 1, 23, 45, 90};

    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);

    print_intersection(arr1, arr2, size1, size2);

    return 0;
}