class Solution {
public:
    int bs(vector<int>nums, int si, int ei, int target){
        if(si>ei)
            return -1;
        
        int mid = (si+ei)/2;
        
        if(nums[mid]==target)
            return mid;
        
        else if(nums[mid]>=nums[si]){
            if(target<nums[mid] && target>=nums[si])
                return bs(nums, si, mid-1, target);
            else
                return bs(nums, mid+1, ei, target);
        }
        else{
            if(target<=nums[ei] && target>nums[mid])
                return bs(nums, mid+1, ei, target);
            else
                return bs(nums, si, mid-1, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size()-1, target);
    }
};
    
    
// 4 5 6 7 8 0 3