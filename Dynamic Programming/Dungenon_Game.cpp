// Problem Link : https://leetcode.com/problems/dungeon-game/
// Solution type : Dynamic Programing(Top-down)

// We want to reach the last cell of the dungeon which means that our health should be greater than 1 when we reach there. So the best way to calculate the minimum health required is by checking for the last cell and going our way upwards. The answer will be the value we get on arriving at the first cell;

// -2 	 -3	   3
// -5	 -10   1
// 10	  30  -5  <-  when we arrive here our health will be reduced by 5.
// 				So we need minimum 6 health to survive when we reach here. val = (1- (-5) = 6)

// If this value was positive we dont need to worry and the minimum energy we need is 1. 
// Suppose the value was +5 then 1-5 = -4.  -4<1 => so ans is 1. i.e max(1,val).
// Now for simplicity and to avoid the checks on the border we can create our dp with 1 additional bottom row and 1 additional rightmost column. (Similar to the dp we use in LCS and other problem).

// Also what values should we fill our dp with?
// Well the answer is quite obvious the maximum possible value. For c++ we can use INT_MAX;
// Our dp looks like this:

// -2  -3   3  m      m -> denotes max 
// -5  10   1  m
// 10  30  -5  1   -> note: we have two value as 1 for the last element (I will explain this as we proceed)
//  m   m   1 m
 
//  suppose the dimensions of dungeon matirx was "r x c", for our dp will be " r+1 x c+1".
//  We will start our iteration 
//  from the value -5 that is the cell our princess is located.
//  We first have to see which value is minimum from that cell (the one on the right or bottom).
//  i.e. which cell requres less health to travel to
//  for this cell is (one which holds the princess):
//  val = min of dp[i+1][j] and dp[i][j+1] (min of bottom and right).
//  so val = min(1,1) = 1;
//  Also we have to reduce the health required to stay in the current cell.
//  val = val - dungeon[i][j] = 1 - (-5) = 6;
//  Now as i explained earlier:
//  dp[i][j] = max(1,val)   => if val is negetive that means we dont have to spend health on this cell so it should be kept minimum i.e. 1.
 
//  So we had to keep both values 1 as instead of max as for calculating the health for princess' cell we only need 1 health minimum. 
 
//  Now let's see for 2nd row 3rd column (one above the princess)
//  val = min(m,6) - 1;   (6 because the dp holds value 6 for princess' cell which was calculated earlier)
//  val = 5.
//  dp[1][2] = 5; So when we are at this cell we need health atleast 5. 
//  As we will gain 1 health and then move on to the princess's cell giving up  5  health and thus in this way we can calculate all the values. Code contains further explanation.

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();   // no of rows
        if(r == 0) return 0; // if empty then return 0
        int c = dungeon[0].size();  // no of columns
		// DP with r+1 x c+1 dimension and all values initialized to INT_MAX
        vector<vector<int>>dp(r+1,vector<int>(c+1,INT_MAX));
		// Initializing the cell to the bottom and right of princess' cell with value 1.
        dp[r-1][c] = 1;
        dp[r][c-1] = 1;
		//Iterating over dp excluding the additional row and column we added.
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                int val = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j];  // value is minimum health to land on next - health need to stay
                dp[i][j] = max(1,val); // minimum value required is 1. maximum is the +ve value we calculated.
            }
        }
        
        return dp[0][0];  // The first element contains the minimum health needed to rescue the princess.
    }
};
