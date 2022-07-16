class Solution {
public:
    int mod;
    int helper(int m, int n, int maxMove, int i, int j, int moves, int***dp){
        if(i<0 || j<0 || i>=m || j>=n){
            if(moves<=maxMove){
                return 1;
            }   
            return 0;
        }
        if(moves>=maxMove)
            return 0;
        
        if(dp[i][j][moves]!=-1)
            return dp[i][j][moves]%mod;
        
        
        int ans = 0;
        ans = (ans + helper(m, n, maxMove, i+1, j, moves+1, dp))%mod;
        ans = (ans + helper(m, n, maxMove, i-1, j, moves+1, dp))%mod;
        ans = (ans + helper(m, n, maxMove, i, j+1, moves+1, dp))%mod;
        ans = (ans + helper(m, n, maxMove, i, j-1, moves+1, dp))%mod;
        
        dp[i][j][moves]=ans;
        return dp[i][j][moves]%mod;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        mod = 1000000007;
        int ***dp = new int**[m];
        for(int i=0; i<m; i++){
            dp[i]=new int*[n];
            for(int j=0; j<n; j++){
                dp[i][j] = new int[maxMove+1];
                for(int k=0; k<maxMove+1; k++){
                    dp[i][j][k]=-1;
                    //cout<<dp[i][j][k]<<",";
                }
                //cout<<" ";
            }
            //cout<<endl;
        }
        int ans = (int)helper(m, n, maxMove, startRow, startColumn, 0, dp)%1000000007;
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         for(int k=0; k<maxMove+1; k++){
        //             cout<<dp[i][j][k]<<",";
        //         }
        //         cout<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};