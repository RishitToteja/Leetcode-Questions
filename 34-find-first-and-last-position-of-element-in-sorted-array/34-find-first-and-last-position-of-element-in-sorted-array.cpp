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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> :: iterator index;
        index=lower_bound(nums.begin(),nums.end(),target);
        int l = index - nums.begin();
        
        vector<int> :: iterator index2;
        index2=upper_bound(nums.begin(),nums.end(),target);
        int r = index2 - nums.begin();
        if(bs(nums, target, 0, nums.size()-1)==-1)
            return {-1, -1};
        return {l, r-1};
    }
};