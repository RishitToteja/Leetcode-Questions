class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int>freq;
        unordered_map<int, int>hyp;
        
        for(int i:nums){
            freq[i]++;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(freq[nums[i]] > 0){
                if(hyp[nums[i]] > 0){
                    freq[nums[i]]--;
                    hyp[nums[i]]--;
                    hyp[nums[i]+1]++;
                }
                else if(freq[nums[i]+1]>0 && freq[nums[i]+2]>0){
                    freq[nums[i]]--;
                    freq[nums[i]+1]--;
                    freq[nums[i]+2]--;
                    hyp[nums[i]+3]++;
                }
                else
                    return false;
            }
        }
        for(auto i: freq){
            if(i.second>0)
                return false;
        }
        return true;
    }
};