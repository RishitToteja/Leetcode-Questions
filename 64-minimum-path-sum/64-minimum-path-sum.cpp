class Solution {
public:
    int dp[201][201] = {0};
    
    int helper(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(dp[i][j]>0)
            return dp[i][j];
        else{
            int a = INT_MAX;
            if(i+1<m){
                a = min(a, grid[i][j] + helper(grid, i+1, j, m, n));
            }
            if(j+1<n){
                a = min(a, grid[i][j] + helper(grid, i, j+1, m, n));
            }
            return dp[i][j]=a;
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return helper(grid,0,0,m,n);
        
    }
};