class Solution {
public:
    int dp[1000000] = {0};
    int pows(int n){
        if(n == 1){
            return 1;
        }
        if(dp[n] > 0){
            return dp[n];
        }
        
        if(n%2 == 0){
            dp[n] = 1 + pows(n/2);
            
        }
        else{
            dp[n] = 1 + pows((3*n) + 1);
            
        }
        
        return dp[n];
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>>arr;
        for(int i=lo; i<=hi; i++){
            arr.push_back({pows(i), i});
        }
        sort(arr.begin(), arr.end());
        
        return arr[k-1].second;
    }
};