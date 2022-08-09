class Solution {
public:
    int dp[2501][2501];
    int helper(vector<int>&nums, int idx, int prev){
        if(idx>=nums.size())
            return 0;
        
        if(dp[idx][prev]!=-1){
            return dp[idx][prev];
        }
        int ans = INT_MIN;
        
        if(prev==nums.size() || nums[idx]>nums[prev]){
            ans = 1+ helper(nums, idx+1, idx);
        }
        ans = max(ans, helper(nums, idx+1, prev));
        
        return dp[idx][prev]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        for(int i=0;i<2501;++i)
        {
            for(int j=0;j<2501;++j)
            {
                dp[i][j]=-1;
            }
        }
        int ans = INT_MIN;
        vector<int>dp(nums.size()+1, -1);
        for(int i=0; i<nums.size(); i++){
            ans = max(ans, helper(nums, i, nums.size()));
        }
        return ans;
    }
};