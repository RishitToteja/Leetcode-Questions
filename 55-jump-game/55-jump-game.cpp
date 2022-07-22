class Solution {
public:
    int *dp;
    
    Solution(){
        dp = new int[10001];
        for(int i=0; i<10001; i++){
            dp[i]=-1;
        }
    }
    
    bool canJump(vector<int>& nums, int idx = 0) {
        if(idx == nums.size()-1)
            return true;
        if(dp[idx] !=-1){
            return dp[idx];
        }
        
        int maxJump = nums[idx];
        
        for(int i=1; i<=maxJump; i++){
            bool bol = canJump(nums, idx+i);
            if(bol)
                return dp[idx]=true;
        }
        return dp[idx]=false;
    }
};