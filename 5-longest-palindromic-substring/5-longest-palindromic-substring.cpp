class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        
        pair<int, pair<int, int>>p = {INT_MIN, {-1, -1}};
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
            if(1>p.first){
                    p = {1, {i, i}};
            }
        }
        
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = 1;
                if(2>p.first){
                    p = {2, {i, i+1}};
                }
            }
            else
                dp[i][i+1] = 0;
        }
        int j = 2;
        
        while(j<n){
            for(int i=0; i<n-j; i++){
                if(s[i]==s[i+j] && dp[i+1][i+j-1]==1){
                    dp[i][i+j]=1;
                    if(j+1>p.first){
                        p = {j+1, {i, j+i}};
                    }
                }
                else{
                    dp[i][i+j]=0;
                }
            }
            j++;
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        string se = "";
        for(int i=p.second.first; i<=p.second.second; i++){
            se += s[i];
        }
        return se;
    }
};

// 0, 1
// 1, 2
// 2, 3