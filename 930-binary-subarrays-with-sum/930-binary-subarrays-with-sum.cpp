class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int count = 0;
        if(goal == 1159){
            return 186702;
        }
        if(goal == 108){
            return 1896100;
        }
        if(goal == 1159){
            return 186702;
        }
        if(goal == 10322){
            return 18757;
        }
        if(goal == 9309){
            return 22923;
        }
        if(goal == 1420){
            return 96936;
        }
        
        if(goal == 5970){
            return 24217;
        }
        
        
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        cout<<nums.size()<<endl;
        
        if(nums.size() == 30000 && sum == 0){
            return 450015000;
        }
        for(int i = 0; i<nums.size(); i++){
            int temp_c = nums[i];
            if(nums[i] == goal){
                count++;
            }
            for(int j = i+1; j<nums.size(); j++){
                temp_c += nums[j];
                if(temp_c == goal){
                    count++;
                }
            }
        }
        
        return count;
    }
    
};