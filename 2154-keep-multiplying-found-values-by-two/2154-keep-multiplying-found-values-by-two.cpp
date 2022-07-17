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
        unordered_map<int, int>pq;
        for(int i=0; i<nums.size(); i++){
            pq[nums[i]]++;
        }
        while(pq[original]>0){
            original*=2;
        }
        return original;
        
    }
};