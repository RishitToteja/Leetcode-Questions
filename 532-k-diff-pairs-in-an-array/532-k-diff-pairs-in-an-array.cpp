class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k==0){
            unordered_map<int, int>mp;
            int cnt = 0;
            for(int i=0; i<nums.size(); i++){
                mp[nums[i]]++;
            }
            for(auto i: mp){
                if(i.second>1)cnt++;
            }
            return cnt;
        }
        set<int>s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        vector<int>arr;
        for(auto i: s){
            arr.push_back(i);
        }
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            int req = arr[i]+k;
            if(s.find(req) != s.end())cnt++;
        }

        return cnt;
    }
};