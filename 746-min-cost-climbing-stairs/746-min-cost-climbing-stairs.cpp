class Solution {
public:
    int dp[1001]={0};
    int mincost(int*a, int n){
        if(n<=0)
            return 0;
        if(dp[n]>0)
            return dp[n];
        else{
            int x = a[0];
            int y = mincost(a+1, n-1);
            int z = mincost(a+2, n-2);
            dp[n]= x + min(y, z);
            return dp[n];
        }
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int*a = new int[cost.size()];
        for(int i=0; i<cost.size(); i++){
            a[i]=cost[i];
        }
        return min(mincost(a, cost.size()), mincost(a+1, cost.size()-1));
    }
};