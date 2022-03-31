class Solution {
public:
    bool boolean(vector<int>nums, int mid, int m){
        int sum = 0;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>mid){
                return false;
            }
            
            sum +=nums[i];
            if(sum>mid){
                count++;
                sum = nums[i];
            }
        }
        count+=1;
        if(count <= m){
            return true;
        }
        
        else{
            return false;
        }
    }
    int splitArray(vector<int>& nums, int m) {
        int si = 0;
        int ei = 0;
        int ans;
        for(int i: nums){
            if(i>si){
                si= i;
            }
            ei+=i;
        }
        while(si<=ei){
            int mid = (si+ei)/2;
            if(boolean(nums, mid, m)){
                ans = mid;
                ei = mid-1;
            }
            else{
                si = mid+1;
            }
        }
        
        return ans;
    }
};