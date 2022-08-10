class Solution {
public:
    bool first(vector<int>&nums, int si, int ei){
        if(ei-si==1){
            if(nums[si]==nums[si+1])
                return true;
        }
        return false;
    }
    bool second(vector<int>&nums, int si, int ei){
        if(ei-si==2){
            if(nums[si]==nums[si+1] && nums[si+1]==nums[si+2])
                return true;
        }
        return false;
    }
    bool third(vector<int>&nums, int si, int ei){
        if(ei-si==2){
            if(nums[si]+1==nums[si+1] && nums[si+1]+1==nums[si+2])
                return true;
        }
        return false;
    }
    bool check(vector<int>&nums, int si, int ei){
        return first(nums, si, ei)||second(nums, si, ei)||third(nums, si, ei);
    }
    
    bool helper(vector<int>& nums, int si, int ei, vector<int>&dp) {
        if(check(nums, si, ei))
            return true;
        
        bool bol = false;
        if(dp[si]!=-1)
            return dp[si];
        
        if(si==ei || ei-si == 1 && nums[si]!= nums[ei])
            return false;
        if(check(nums, si, si+1)){
            bol =  helper(nums, si+2, ei, dp);
        }
        if(!bol && check(nums, si, si+2)){
            bol = bol || helper(nums, si+3, ei, dp);
        }
        return dp[si]=bol;
    }
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return helper(nums, 0, nums.size()-1, dp);
    }
           
};