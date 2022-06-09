class Solution {
public:
    int dp[46] = {0};
    Solution(){
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
    }

    int climbStairs(int n) {
        if(n<=0)
            return 0;
        if(dp[n]>0)
            return dp[n];
        int a = climbStairs(n-1);
        int b = 0;
        if(n-2>=0)
            b = climbStairs(n-2);
        dp[n] = a+b;
        return dp[n];
    }
};