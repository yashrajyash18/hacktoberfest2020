/*

Problem Link - https://leetcode.com/problems/unique-paths/
Explanation - In this solution we are starting from the destination in top down manner and from there we are trying to reach the origin 0,0. We are taking both the cases 
 up and left and at the end we are adding the total number of possible paths 
 
 
 */
 
 
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m+1][n+1];
        return calculate(m-1,n-1,dp);
        
    }
    
    private int calculate(int i, int j, int[][] dp){
        if (i == 0 &&  j == 0){
            return 1;
        }
        if (i < 0 || j < 0){
            return 0;
        }
        if (dp[i][j] != 0){
            return dp[i][j];
        }
        int left = calculate(i-1,j,dp);
        int up = calculate(i,j-1,dp);
        return dp[i][j] = up+left;
    }
}
