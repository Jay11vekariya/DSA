/*
    121. [Best Time to Buy and Sell Stock]

    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that
    stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

    Example:
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

public class Stock {
    public static int maxProfit(int[] prices) {

        int buyPrice = prices[0]; // Minimum price seen so far
        int maxProfit = 0;        // Maximum profit found so far

        for (int i = 1; i < prices.length; i++) {

            if (prices[i] > buyPrice) {

                // Sell today and calculate profit
                int currProfit = prices[i] - buyPrice;

                // Update maximum profit
                maxProfit = Math.max(maxProfit, currProfit);
            }
            else {
                // Found a cheaper buying price
                buyPrice = prices[i];
            }
        }

        return maxProfit;
    }
    public static void main(String args[]){
        int prices[] = {7,1,5,3,6,4};
        System.out.println(maxProfit(prices));
    }
}


/*
    Best Time to Buy and Sell Stock - Optimal Approach

    Purpose:
    Find the maximum profit by buying a stock on one day
    and selling it on a future day.

    Main Idea:
    Keep track of the minimum stock price seen so far (buyPrice)
    and calculate the profit whenever the current price is greater
    than the buying price.

    Approach:

    1. Initialize:
           buyPrice = prices[0]
           maxProfit = 0

       buyPrice represents the cheapest buying price seen so far.

    2. Traverse the array from left to right.

    3. If current price > buyPrice:
           We can sell the stock today and make a profit.

           currProfit = prices[i] - buyPrice

           Then update:
           maxProfit = max(maxProfit, currProfit)

    4. Otherwise:
           The current stock price is smaller than or equal to
           buyPrice, so update buyPrice.

           buyPrice = prices[i]

       This gives us a cheaper buying price for future days.

    Example:
        prices = {7, 1, 5, 3, 6, 4}

        Price     buyPrice     currProfit     maxProfit
        ------------------------------------------------
          7           7            -              0
          1           1            -              0
          5           1            4              4
          3           1            2              4
          6           1            5              5
          4           1            3              5

        Best transaction:
            Buy  = 1
            Sell = 6

            Profit = 6 - 1 = 5

    Why does buying always happen before selling?

        We traverse from left to right, so buyPrice always comes
        from the current or an earlier day. Profit is calculated
        using a later/current selling day while traversing forward.

    If prices always decrease:
        prices = {7, 6, 4, 3, 1}

        No profitable transaction exists, so maxProfit remains 0.

    Time Complexity  : O(n)
        The array is traversed only once.

    Space Complexity : O(1)
        Only a few variables are used.
*/