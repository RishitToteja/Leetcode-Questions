class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums){
        int running_sum = 0;
        int max_sum = 0;
        
        map<int, int>pq;
        int si = 0;
        int ei = 0;
        
        while(ei<nums.size()){
            if(pq.find(nums[ei]) == pq.end()){
                pq.insert({nums[ei], 1});
                running_sum += nums[ei];
                max_sum = max(running_sum, max_sum);
                ei++;
            }
            else{
                pq.erase(nums[si]);
                running_sum -= nums[si];
                si++;
            }
        }
        
        return max_sum;
    }
};