/*


Problem Link  - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 Explanation - In this question we will simply check for each day if we are getting the profit then we will sell otherwise we will not add to our final answer/


*/


class Solution {
    public int maxProfit(int[] prices) {
        int curr = 0;
        for (int i =0; i < prices.length-1; i++){
            curr = Math.max(curr,curr+(prices[i+1]-prices[i]));
        }
        return curr;
    }
}
