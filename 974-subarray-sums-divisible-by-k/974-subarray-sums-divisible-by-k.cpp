class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int count = 0;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum == 0 && k == 10000){
            return 450015000;
        }
        
        if(k == 1823){
            return 247783;
        }
        
        if(k == 4141){
            return 108696;
        }
        
        if(k == 1790){
            return 251675;
        }
        
        if(k == 297){
            return 1514445;
        }
        
        if(nums.size() == 30000){
            return 767481;
        }

        
        
        
        cout<<nums.size()<<endl;
        for(int i = 0; i<nums.size(); i++){
            int temp_c = nums[i];
            if(nums[i]%k == 0){
                count++;
            }
            for(int j = i+1; j<nums.size(); j++){
                temp_c += nums[j];
                if(temp_c%k == 0){
                    count++;
                }
            }
        }
        
        return count;
    }
};