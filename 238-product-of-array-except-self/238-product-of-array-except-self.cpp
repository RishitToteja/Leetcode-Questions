class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int product = 1;
        
        for(int i = 0; i<nums.size(); i++){
            product *= nums[i];
        }
        
        int product_w0 = 1;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0)
                product_w0 *= nums[i];
        }
        
        vector<int>zeros;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeros.push_back(i);
            }
        }
        
        vector<int>ans;
        


        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0){
                ans.push_back(product/nums[i]);
            }
            
            if(nums[i] == 0 && zeros.size()>1){
                ans.push_back(0);
            }
            
            if(nums[i] == 0 && zeros.size() == 1){
                ans.push_back(product_w0);
            }
        }
        return ans;
            
    }
};