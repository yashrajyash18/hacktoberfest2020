// Problem Link : https://leetcode.com/problems/making-a-large-island/
// Solution Type : Depth First Search and Graph Coloring

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    unordered_map<int, int> components;
    
    void dfs(vector<vector<int>>& grid, int& row, int& col, int r, int c, int nextregion) {
        if(r < 0 || r == row || c < 0 || c == col || grid[r][c] != 1) return;
        grid[r][c] = nextregion;
        components[nextregion] += 1;
        for(int i=0; i<4; i++) {
            int ro = r + dx[i];
            int co = c + dy[i];
            dfs(grid, row, col, ro, co, nextregion);
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int region = 2, ans = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] != 1) continue;
                dfs(grid, row, col, i, j, region++);
                ans = max(ans, components[region-1]);
            }
        }
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++){
                if(grid[i][j] != 0) continue;
                unordered_set<int> uniquecomp;
                for(int dir=0; dir<4; dir++) {
                    int x = i + dx[dir];
                    int y = j + dy[dir];
                    if(x < 0 || x == row || y < 0 || y == col || grid[x][y] == 0) continue;
                    uniquecomp.insert(grid[x][y]);
                }
                int sizeFormed = 1;
                for(auto it : uniquecomp){
                    sizeFormed += components[it];
                }
                ans = max(ans, sizeFormed); 
            }
        }
        return ans;
    }
};
