class Solution {
public:
    int dp[101][101];
    int helper(int i, int j, int m, int n, int&count){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i<0 || i>=m || j<0 || j>= n){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int a = helper(i, j+1, m, n, count);
        int b = helper(i+1, j, m, n, count);
        
        return dp[i][j]=a+b;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        int ans = helper(0, 0, m, n, ans);
        return ans;
    }
};