class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int except_0 = 1;
        int count_0 = 0;
        
        for(int i: nums){
            if(i != 0)
                except_0*=i;
            else
                count_0++;
        }
        vector<int>a(nums.size(), 0);
        if(count_0>1)
            return a;
        
        vector<int>ans;
        for(int i: nums){
            if(i==0)
                ans.push_back(except_0);
            else{
                if(count_0==1)
                    ans.push_back(0);
                else
                    ans.push_back(except_0/i);
            }
        }
        return ans;
    }
};