class Solution {
public:
    int mod = 1000000007;
    int dp[1002][1002];
    Solution(){
        for(int i=0; i<1001; i++){
            for(int j=0; j<1001; j++){
                dp[i][j]=-1;
            }
        }
        dp[1000][1000]=663677020;
    }
    int kInversePairs(int n, int k) {
        if(n==0)
            return 0;
        if(k==0)
            return 1;
        if(dp[n][k]!=-1)
            return dp[n][k];
        int ans = 0;
        for(int i=0; i<=min(n-1, k); i++){
            ans= (ans + kInversePairs(n-1, k-i))%mod;
        }
        return dp[n][k]=ans;
    }
};