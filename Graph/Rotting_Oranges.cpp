// Problem Link :- https://leetcode.com/problems/rotting-oranges/
// solution type :- Breath First Search

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool isSafe(vector<vector<int>>& grid, int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] != 0) tot++;
            }
        }
        while(!q.empty()) {
            int sz = q.size();
            cnt += sz;
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0; i<4; i++) {
                    int r1 = r + dx[i];
                    int c1 = c + dy[i];
                    if(isSafe(grid, m, n, r1, c1)){
                        grid[r1][c1] = 2;
                        q.push({r1, c1});
                    }
                }
            }
            if(!q.empty()) time++;
        }
        return tot == cnt ? time : -1;
    }
};
