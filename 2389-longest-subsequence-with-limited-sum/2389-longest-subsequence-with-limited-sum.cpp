class Solution {
public:
    int helper(vector<int>&nums, int sum, int curr, int idx, int len){
        if(idx>=nums.size())return len;
        else{
            int a = helper(nums, sum, curr, idx+1, len);
            int b = INT_MIN;
            if(curr+nums[idx]<=sum){
                b = helper(nums, sum, curr+nums[idx], idx+1, len+1);
            }
            return max(a,b);
        }
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            nums[i] = nums[i]+nums[i-1];
        }
        vector<int>ans;
        for(int i=0; i<queries.size(); i++){
            ans.push_back(upper_bound(nums.begin(), nums.end(), queries[i])-nums.begin());
        }
        return ans;
    }
};