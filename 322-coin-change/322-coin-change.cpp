class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        for(int i=0;i<n;i++)
            dp[i][0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                int not_take=1e9,take=1e9;
                if(i>0)
                    not_take=dp[i-1][j];
                if(j-coins[i]>=0)
                    take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take,not_take);
            }
        }
        int ans= dp[n-1][amount];
        if(ans>=1e9)
            return -1;
        return ans;
    }
};