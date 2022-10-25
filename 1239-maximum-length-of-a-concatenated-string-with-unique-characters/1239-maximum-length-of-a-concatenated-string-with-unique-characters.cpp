class Solution {
public:
    int max(int a, int b){
        if(a>b)return a;
        return b;
    }
    unordered_map<int, unordered_map<char, int>>dp;
    
    int helper(int idx, unordered_map<char, int>t, int len, int n){
        if(dp.find(idx) == dp.end()){
            if(idx<n){
                return helper(idx+1, t,len, n);
            }
            else{
                return len;
            }
        }
        
        else{
            int a = helper(idx+1, t, len, n);
            int b = INT_MIN;
            unordered_map<char, int>temp = t;
            temp.insert(dp[idx].begin(), dp[idx].end());
            if(temp.size()==t.size()+dp[idx].size())
                b = helper(idx+1, temp, len+dp[idx].size(), n);
            
            return max(a, b);
        }
    }
    int maxLength(vector<string>& arr) {
        for(int i=0; i<arr.size(); i++){
            unordered_map<char, int>mp;
            for(int j=0; j<arr[i].size(); j++){
                mp[arr[i][j]]++;
            }
            if(arr[i].size()==mp.size())
                dp[i] = mp;
        }
        return helper(0, {}, 0, arr.size());
    }
};