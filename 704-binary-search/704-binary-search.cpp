class Solution {
public:
    int helper(vector<int>nums, int si, int ei, int target){
        if(si>ei){
            return -1;
        }
        else{
            int mid = (si+ei)/2;
            if(nums[mid] == target){
                return mid;
            }
            
            else if(nums[mid] > target){
                return helper(nums, 0, mid-1, target);
            }
            
            else{
                return helper(nums, mid+1, ei, target);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size()-1, target);
    }
};