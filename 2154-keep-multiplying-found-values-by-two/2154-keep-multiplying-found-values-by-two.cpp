class Solution {
public:
    bool bs(vector<int>nums, int si, int ei, int key){
        if(si>ei)
            return false;
        int mid = (si+ei)/2;
        if(nums[mid]==key)
            return true;
        else if(nums[mid]>key)
            return bs(nums, 0, mid-1, key);
        else
            return bs(nums, mid+1, ei, key);
    }
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        
        while(bs(nums, 0, nums.size()-1, original)){
            original*=2;
        }
        return original;
        
    }
};