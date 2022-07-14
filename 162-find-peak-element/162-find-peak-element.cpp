class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)return 0;
        if(nums[nums.size()-2]<nums[nums.size()-1])
            return nums.size()-1;
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                int a = nums[i];
                int b = nums[i+1];
                if(a>b)
                    return 0;
            }
            else if(i==nums.size()-1){
                continue;
            }
            else{
                int a = nums[i];
                int b = nums[i+1];
                int c = nums[i-1];
                if(a>b && a>c)
                    return i;
            }
            
        }
        return -1;
    }
};