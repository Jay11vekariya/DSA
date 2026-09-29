#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int> &height)
{
    int max_area = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right)
    {
        int wd = right - left;
        int ht = min(height[left], height[right]);
        int area = wd * ht;
        max_area = max(max_area, area);

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return max_area;
}

int main()
{

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height);
    return 0;
}