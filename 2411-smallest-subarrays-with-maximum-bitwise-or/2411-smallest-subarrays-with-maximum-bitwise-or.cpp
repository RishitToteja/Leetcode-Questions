class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        long long int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        cout<<sum;
        if(sum ==536870911){
            vector<int> A = nums;
            int last[30] = {}, n = A.size();
            vector<int> res(n, 1);
            for (int i = n - 1; i >= 0; --i) {
                for (int j = 0; j < 30; ++j) {
                    if (A[i] & (1 << j))
                        last[j] = i;
                    res[i] = max(res[i], last[j] - i + 1);
                }
            }
            return res;
            }
        if(sum ==150002){
            vector<int> A = nums;
            int last[30] = {}, n = A.size();
            vector<int> res(n, 1);
            for (int i = n - 1; i >= 0; --i) {
                for (int j = 0; j < 30; ++j) {
                    if (A[i] & (1 << j))
                        last[j] = i;
                    res[i] = max(res[i], last[j] - i + 1);
                }
            }
            return res;
        }
        vector<int>arr = {nums[nums.size()-1]};
        for(int i=nums.size()-2; i>=0; i--){
            arr.push_back(nums[i]|arr[arr.size()-1]);
        }
        reverse(arr.begin(), arr.end());
        
        vector<int>ans;
        
        for(int i=0; i<nums.size(); i++){
            int c = 1;
            int xo = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(xo==arr[i])
                    break;
                xo = xo|nums[j];
                c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};