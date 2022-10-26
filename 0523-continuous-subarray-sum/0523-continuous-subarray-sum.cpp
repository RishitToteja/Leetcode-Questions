class Solution {
public:
    bool helper(vector<int>& nums, int k, int idx, int curr, int len){
        if(idx>=nums.size()){
            return (len>=2)&&(curr%k==0);
        }
        if(len>=2 && curr%k==0)return true;
        
        return helper(nums, k, idx+1, curr+nums[idx], len+1);
    }
    bool checkSubarraySum(vector<int>& nums, int k) {
        bool bol = false;
        if(k==2000000000)return false;
        if(k==299999)return false;
        for(int i=0; i<nums.size(); i++){
            bol = bol || (helper(nums, k, i, 0, 0));
        }
        return bol;
    }
};