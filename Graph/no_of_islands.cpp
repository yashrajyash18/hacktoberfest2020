class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    queue<pair<int, int>> q;
                    grid[i][j] = '0';
                    q.push({i, j});
                    int dx[4] = {-1, 1, 0, 0};
                    int dy[4] = {0, 0, -1, 1};
                    while(!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for(int i=0; i<4; i++) {
                            int x = r + dx[i];
                            int y = c + dy[i];
                            if(x >= 0 && x < m and y >= 0 && y < n) {
                                if(grid[x][y] == '1') {
                                    grid[x][y] = '0';
                                    q.push({x, y});
                                }
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};