class Solution {
public:
    int find1sInIsland(vector<vector<int>>&grid, int row, int col){
        if(row<0 || col < 0 || row>=grid.size() || col >= grid[0].size())
            return 0;
        else if(grid[row][col]==0)
            return 0;
        grid[row][col]=0;
        return 1 + find1sInIsland(grid, row-1, col) + find1sInIsland(grid, row+1, col) + find1sInIsland(grid, row, col-1) + find1sInIsland(grid, row, col+1);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int largestIsland = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                    largestIsland = max(largestIsland, find1sInIsland(grid, i, j));
            }
        }
        
        return largestIsland;
    }
};