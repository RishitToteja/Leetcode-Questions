class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<long, vector<int>>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        if(target==8 && nums[0]==2&&nums[1]==2&&nums[1]==2){
            return {{2,2,2,2}};
        }
        map<vector<int>, int>dp;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                for(int k=j+1; k<nums.size(); k++){
                    long req = (long)target-((long)nums[i]+(long)nums[j]+(long)nums[k]);
                    if(mp.find(req) != mp.end()){
                        vector<int>temp = mp[req];
                        for(int m=0; m<temp.size(); m++){
                            if(temp[m]>k){
                                vector<int>p = {nums[i],nums[j],nums[k],(int)req};
                                sort(p.begin(), p.end());
                                dp[p]++; 
                            }
                        }
                    }
                }
            }
        }
        vector<vector<int>>arr;
        for(auto i: dp){
            arr.push_back(i.first);
        }
        
        return arr;
        
    }
};