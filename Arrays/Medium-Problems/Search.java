/*

    [Search in Rotated Sorted Array]

    Given an integer array nums containing distinct elements, which was originally sorted in ascending order but may have been 
    rotated at an unknown index, and an integer target, find the index of target in the array.
    If the target exists, return its index. Otherwise, return -1.
    The solution must have a time complexity of O(log n).

    Example:
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

*/


public class Search {

    public static int search(int[] nums, int target) {

        int low = 0;
        int high = nums.length - 1; // Last valid index

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                // Target lies inside the sorted left half
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                }
                // Target lies in the other half
                else {
                    low = mid + 1;
                }
            }

            // Otherwise, right half is sorted
            else {

                // Target lies inside the sorted right half
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                }
                // Target lies in the other half
                else {
                    high = mid - 1;
                }
            }
        }

        // Target does not exist
        return -1;
    }

    public static void main(String args[]) {
        int nums[] = { 5, 6, 7, 2, 3, 4 };
        int target = 3;
        System.out.println(search(nums, target));
    }
}

/*
    Modified Binary Search - Search in Rotated Sorted Array

    Problem:
    Given a sorted array that may have been rotated, find the index
    of the given target. Return -1 if the target does not exist.

    Approach:
    We use modified Binary Search.

    In a rotated sorted array, at least one half around 'mid'
    will always be sorted.

    1. Initialize:
           low  = 0
           high = nums.length - 1

    2. Find the middle index:
           mid = low + (high - low) / 2

    3. If nums[mid] == target:
           return mid.

    4. Check whether the LEFT half is sorted:
           nums[low] <= nums[mid]

       If the left half is sorted:
           - If target lies between nums[low] and nums[mid],
             search the left half:
                 high = mid - 1

           - Otherwise, search the right half:
                 low = mid + 1

    5. Otherwise, the RIGHT half is sorted.

       If the right half is sorted:
           - If target lies between nums[mid] and nums[high],
             search the right half:
                 low = mid + 1

           - Otherwise, search the left half:
                 high = mid - 1

    6. Continue until target is found or low > high.

    Example:
        nums   = {4, 5, 6, 7, 0, 1, 2}
        target = 0

        low=0, high=6, mid=3
        nums[mid]=7

        Left half {4,5,6,7} is sorted.
        Target 0 is not in this range.
        So search right -> low = 4

        low=4, high=6, mid=5
        nums[mid]=1

        Left half {0,1} is sorted.
        Target 0 lies in this range.
        So search left -> high = 4

        low=4, high=4, mid=4
        nums[mid]=0 -> Target found.

        Return index 4.

    Time Complexity  : O(log n)
        Search space is reduced to half after every iteration.

    Space Complexity : O(1)
        Only low, high and mid variables are used.

    Note:
        This approach assumes all elements are distinct.
*/