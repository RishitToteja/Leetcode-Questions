class Solution {
public:
    bool bs(vector<int>num, int si, int ei, int target){
        if(si>ei){
            return false;
        }
        
        else{
            int mid = (si+ei)/2;
            
            if(num[mid] == target){
                return true;
            }
            
            else{
                if(target<num[mid]){
                    return bs(num, si, mid-1, target);
                }
                else{
                    return bs(num, mid+1, ei, target);
                }
            }
        }
    }
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        return bs(nums, 0, nums.size()-1, target);
    }
};