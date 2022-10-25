class Solution {
public:
    vector<int> dp;
    Solution(){
        vector<int> temp(10001, INT_MAX-100000);
        dp = temp;
    }
    int jump(vector<int>& nums, int idx = 0) {
        
        if(idx==nums.size()-1){
            return 0;
        }
        if(dp[idx]!=INT_MAX-100000){
            return dp[idx];
        }
        
        for(int i=1; i<=nums[idx]; i++){
            if(idx+i<nums.size()){
                dp[idx] = min(dp[idx], 1+jump(nums, i+idx));
            }
        }
        return dp[idx];
    }
};