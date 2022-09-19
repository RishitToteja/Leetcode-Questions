class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j, int m, int n){
        grid[i][j]='0';
        if(i-1>=0 && grid[i-1][j]=='1'){
            helper(grid, i-1, j, m, n);
        }
        if(i+1<m && grid[i+1][j]=='1'){
            helper(grid, i+1, j, m, n);
        }
        if(j-1>=0 && grid[i][j-1]=='1'){
            helper(grid, i, j-1, m, n);
        }
        if(j+1<n && grid[i][j+1]=='1'){
            helper(grid, i, j+1, m, n);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    helper(grid, i, j, grid.size(), grid[0].size());
                }
                    
            }
        }
        return cnt;
    }
};