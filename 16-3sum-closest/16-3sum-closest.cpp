class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int ans = INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            int s = nums[i];
            int si=i+1;
            int ei=nums.size()-1;
            while(si<ei){
                int curr = s+nums[si]+nums[ei];
                
                if(curr==target){
                    return target;
                }
                if(ans==INT_MAX || abs(target-curr) < abs(ans-target)){
                    ans = curr;
                }
                
                if(curr-target>0)ei--;
                else{
                    si++;
                }
            }
        
        }
        return ans;
        
    }
};