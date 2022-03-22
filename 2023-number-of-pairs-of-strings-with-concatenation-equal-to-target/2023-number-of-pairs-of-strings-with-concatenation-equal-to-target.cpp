class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count  = 0;
        
        for(int i = 0; i<nums.size(); i++){
            string s1 = nums[i];
            for(int j = 0; j<nums.size(); j++){
                if (i!=j){
                    string s2 = s1;
                    s2 += nums[j];
                    if(s2 == target){
                        count++;
                    }
                }  
            }
        }
        
        return count;
    }
};