class Solution {
public:
    int helper(int*arr, int k, int n, int*dp) {
        
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int m = 0;
        for(int i=1; i<=k; i++){
            if(n-i>=0){
                int a = (*max_element(arr, arr+i)*(i)) + helper(arr+i, k, n-i, dp);
                cout<<a<<endl;
                m = max(m, a);
            }
        }
        dp[n] = m;
        return dp[n];
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int *a = new int[arr.size()];
        for(int i=0; i<arr.size(); i++){
            a[i] = arr[i];
        }
        
        int *dp = new int[arr.size()+1];
        memset(dp, -1, sizeof(int)*(arr.size()+1));
        
        return helper(a, k, arr.size(), dp);
    }
    
};