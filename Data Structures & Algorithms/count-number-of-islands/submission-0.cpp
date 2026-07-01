class Solution {
private:
    void callDFS(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';

        int x_axis[] = {-1, 0, 1, 0};
        int y_axis[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int new_i = i + x_axis[k];
            int new_j = j + y_axis[k];

            if (new_i >= 0 && new_j >= 0 &&
                new_i < grid.size() && new_j < grid[0].size() &&
                grid[new_i][new_j] == '1') {
                
                callDFS(new_i, new_j, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    callDFS(i, j, grid);
                }
            }
        }

        return count;
    }
};