package MaximumSubArray;
/* 
    53. [Maximum Subarray]
    
    Given an integer array nums, find the subarray with the largest sum, and return its sum.

    Example :
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/


public class MaximumSubArray {

    // Brute Force Approach
    // Time: O(n^3) | Space: O(1)
    public static int MaxSubarray1(int nums[]) {

        int currSum = 0;
        int maxSum = Integer.MIN_VALUE;

        // Select starting index of subarray
        for (int start = 0; start < nums.length; start++) {

            // Select ending index of subarray
            for (int end = start; end < nums.length; end++) {

                currSum = 0;

                // Calculate sum of current subarray from start to end
                for (int i = start; i <= end; i++) {
                    currSum += nums[i];
                }

                // Update maximum sum found so far
                maxSum = Math.max(maxSum, currSum);
            }
        }

        return maxSum;
    }


    // Better Approach - Running Sum
    // Time: O(n^2) | Space: O(1)
    public static int MaxSubarray2(int nums[]) {

        int currSum = 0;
        int maxSum = Integer.MIN_VALUE;

        // Select starting index
        for (int start = 0; start < nums.length; start++) {

            // Reset sum for each new starting index
            currSum = 0;

            // Extend subarray one element at a time
            for (int end = start; end < nums.length; end++) {

                // Reuse previous sum instead of calculating it again
                currSum += nums[end];

                maxSum = Math.max(maxSum, currSum);
            }
        }

        return maxSum;
    }


    // Prefix Sum Approach
    // Time: O(n^2) | Space: O(n)
    public static int MaxSubarray3(int nums[]) {

        int currSum = 0;
        int maxSum = Integer.MIN_VALUE;

        // prefix[i] stores sum of elements from index 0 to i
        int[] prefix = new int[nums.length];

        // Build prefix sum array
        prefix[0] = nums[0];

        for (int i = 1; i < prefix.length; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        // Select starting index
        for (int start = 0; start < nums.length; start++) {

            // Select ending index
            for (int end = start; end < nums.length; end++) {

                if (start == 0) {
                    // Sum from index 0 to end is already stored in prefix[end]
                    currSum = prefix[end];
                } 
                else {
                    // Subarray sum = prefix[end] - sum before start
                    currSum = prefix[end] - prefix[start - 1];
                }

                // Shorter version using ternary operator:
                // currSum = (start == 0) ? prefix[end] 
                //                        : prefix[end] - prefix[start - 1];

                maxSum = Math.max(maxSum, currSum);
            }
        }

        return maxSum;
    }


    // Optimal Approach - Kadane's Algorithm
    // Time: O(n) | Space: O(1)
    public static int MaxSubarray4(int nums[]) {

        int currSum = 0;
        int maxSum = Integer.MIN_VALUE;

        for (int i = 0; i < nums.length; i++) {

            // Add current element to running subarray sum
            currSum += nums[i];

            // Update maxSum BEFORE resetting currSum
            // This also handles arrays containing only negative numbers
            maxSum = Math.max(maxSum, currSum);

            // Negative sum cannot help a future subarray,
            // so discard it and start fresh
            if (currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;
    }


    public static void main(String[] args) {

        int[] nums = { 3, -4, 5, 4, -1 };

        System.out.println("Brute Force: " + MaxSubarray1(nums));
        System.out.println("Running Sum: " + MaxSubarray2(nums));
        System.out.println("Prefix Sum: " + MaxSubarray3(nums));
        System.out.println("Kadane's Algorithm: " + MaxSubarray4(nums));
    }
}