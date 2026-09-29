/* 
    136. [Single Number]

    You have given an array in which all elements repeats twice except one element which is single, so find that one element. 
    e.g - {4, 1, 3, 1, 3} then output must be 4 
*/

#include <iostream>
#include <vector>
using namespace std;

// Brute-Force Approach  [Time-Complexity : O(n*n)]
void print_Single(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        bool isSingle = true;
        for (int j = 0; j < vec.size(); j++)
        {
            if (i != j && vec[i] == vec[j])
            {
                isSingle = false;
            }
        }
        if (isSingle)
        {
            cout << vec[i] << " ";
        }
    }
}


int main()
{

    vector<int> vec = {4, 1, 3, 1, 3};
    print_Single(vec);
    return 0;
}
