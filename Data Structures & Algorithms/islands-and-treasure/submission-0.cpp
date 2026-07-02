class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();

        //collecting all treasure cells
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto& dir : directions) {
                int nextR = r + dir[0];
                int nextC = c + dir[1];
                if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n && grid[nextR][nextC] == 2147483647) {
                    grid[nextR][nextC] = grid[r][c]+1;
                    q.push({nextR,nextC});
                }
            }
        }
    }
};
