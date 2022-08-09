class Solution {
public:
    int dp[5001][301];
    int helper(vector<int>&nums, int amt, int idx){
        if(idx>=nums.size())
            return 0;
        if(amt == 0){
            return 1;
        }
        if(dp[amt][idx]!=-1)
            return dp[amt][idx];
        int ans = 0;
        if(nums[idx]<=amt){
            ans += helper(nums, amt-nums[idx], idx);
        }
        ans += helper(nums, amt, idx+1);
        
        return dp[amt][idx]=ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return helper(coins, amount, 0);
    }
};