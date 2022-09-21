class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int sum = 0;
        for(int i=0; i<nums.size();i++){
            if(!(nums[i]&1))
                sum += nums[i];
        }
        for(int i=0; i<queries.size(); i++){
            int val = queries[i][0];
            int idx  = queries[i][1];
            int new_val = nums[idx] + val;
            if(!(nums[idx]&1)){
                sum -= nums[idx]; 
            }
            if(!(new_val&1)){
                sum += new_val;
            }
            nums[idx] = new_val;
            
            ans.push_back(sum);
        }
        return ans;
    }
};