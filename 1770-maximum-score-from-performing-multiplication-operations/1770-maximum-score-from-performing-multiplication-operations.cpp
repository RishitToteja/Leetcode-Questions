class Solution {
public:
    int n;
    int m;
    vector<vector<int>> dp;

    int helper( int i, int j, vector<int>&arr, vector<int>&val){
        if(j==val.size()){
            return 0;
        }
        if(dp[i][j]!=INT_MIN){
            return dp[i][j];
        }
        else{
            int a = helper(i+1, j+1, arr, val) + (arr[i]*val[j]);
            int b = helper(i, j+1, arr, val) + (arr[(n - 1) - (j - i)]*val[j]);
            
            return dp[i][j]=max(a, b);
        }
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return helper(0,0,nums, multipliers);
    }
};