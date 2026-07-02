class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int freshOranges = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1) freshOranges++;
            }
        }
        vector<pair<int, int>> directions = {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}
        };
        int minutes = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(auto[rr,cc]:directions){
                    int nextR = r+rr;
                    int nextC = c+cc;
                    if(nextR>=0 && nextC>=0 && nextR<m && nextC<n && grid[nextR][nextC]==1){
                        grid[nextR][nextC] = 2;
                        q.push({nextR,nextC});
                        freshOranges--;

                    }
                }
        
            }
            if(!q.empty()) minutes++;
        }
        if(freshOranges>0) return -1;

        return minutes;
    }
};
