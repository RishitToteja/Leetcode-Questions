class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>arr;
        arr.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())){
            arr.push_back(nums);
        }
        
        return arr;
    }
};