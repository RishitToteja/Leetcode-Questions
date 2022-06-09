class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>nums, vector<int>&temp, int si){
        if(si>=nums.size())
            return ;
        //ans.push_back(temp);
        helper(nums, temp, si+1);
        vector<int>temp2 = temp;
        temp2.push_back(nums[si]);
        ans.push_back(temp2);
        helper(nums, temp2, si+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp = {};
        ans.push_back(temp);
        helper(nums, temp, 0);
        return ans;
    }
};