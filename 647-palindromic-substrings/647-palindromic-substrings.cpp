class Solution {
public:

int countSubstrings(string s) {
    if(s.length()==0|| s.length()==1)
        return s.length();
    int len=s.length();
    vector<vector<int>> dp(len,vector<int> (len,0));
    //int dp[len][len]={0};
    int ans=0;
    
    for(int i=0;i<len;i++){
        dp[i][i]=1;
        ans++;
    }
    
    int j=0;
    for(int i=1;i<len;i++){
        if(s[i-1]==s[i]){
            dp[i-1][i]=1;
            ans++;
        }
    }
    
    for(int i=2;i<s.length();i++){
        int k=i;
        for(int j=0;j<s.length()-i;j++,k++){
            if(s[k]==s[j] && dp[j+1][k-1]){
                dp[j][k]=1;
                ans++;
            }
            
        }
        
    } 
    
    return ans;
    
}
};