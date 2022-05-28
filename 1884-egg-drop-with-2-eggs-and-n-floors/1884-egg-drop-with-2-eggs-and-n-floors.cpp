class Solution {
public:
    int dp[10005][3];
    int helper(int n, int e){
        if(n<=1 || e == 1){
            return n;
        }
        if(dp[n][e] != -1){
            return dp[n][e];
        }
        else{
            int m = INT_MAX;
            for(int i=1; i<n; i++){
                m = min(m, max(helper(n-i, e), helper(i-1, e-1))+1);
            }
            dp[n][e] = m;
            return dp[n][e];
        }
        
    }
    int twoEggDrop(int n) {
        memset(dp, -1, sizeof(dp));
        
        return helper(n, 2);
    }
};


