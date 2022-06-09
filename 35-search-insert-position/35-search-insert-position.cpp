class Solution {
public:
    int bs(vector<int>nums, int val, int si, int ei){
        if(si>ei)
            return -1;
        else{
            int mid = (si+ei)/2;
            if(nums[mid] == val)
                return mid;
            if(nums[mid]>val)
                return bs(nums, val, 0, mid-1);
            else
                return bs(nums, val, mid+1, ei);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target)-nums.begin();
    }
};