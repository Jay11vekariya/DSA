#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> &height)
{
    int maxArea = 0;
    int n = height.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int wd = j - i;                         // Width
            int ht = min(height[i], height[j]);     // Height
            int area = wd * ht;
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}

int main(){

    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<< maxArea(height);
    return 0;
}