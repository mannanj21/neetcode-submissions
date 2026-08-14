class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            int val = grid[row][col] + 1;
            for(int i = 0; i < 4; i++){
                int r = row + dx[i];
                int c = col + dy[i];
                if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] > val){
                    grid[r][c] = val;
                    q.push({r, c});
                }
            }
        }
    }
};
