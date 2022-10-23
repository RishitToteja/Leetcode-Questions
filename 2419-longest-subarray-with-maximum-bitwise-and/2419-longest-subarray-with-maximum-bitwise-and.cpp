class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int len = 0;
        int m = *max_element(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==m){
                len++;
            }
            if(nums[i]!=m && len!=0){
                ans = max(ans, len);
                len = 0;
            }
        }
        return max(len, ans);
    }
};