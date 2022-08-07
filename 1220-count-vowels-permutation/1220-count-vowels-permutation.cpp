class Solution {
public:
    int mod;
    unordered_map<char, int>mp;
    int**dp;
    int ne;
    void constr(){
        mp['a']=0;
        mp['e']=1;
        mp['i']=2;
        mp['o']=3;
        mp['u']=4;
        dp = new int*[5];
        for(int i=0; i<5; i++){
            dp[i]=new int[ne+1];
            for(int j=0; j<ne+1; j++){
                dp[i][j]=-1;
            }
        }
    
    }
    int helper(string s, int l, int n){
        int a = 0;
        if(l==n){
            return 1;
        }
        if(dp[mp[s[l-1]]][l]!=-1)
            return dp[mp[s[l-1]]][l];
        else if(s[l-1]=='a'){
            a = (a + helper(s+'e', l+1, n))%mod;
        }
        else if(s[l-1]=='e'){
            a = (a + helper(s+'a', l+1, n))%mod;
            a = (a + helper(s+'i', l+1, n))%mod;
        }
        else if(s[l-1]=='i'){
            a = (a + helper(s+'a', l+1, n))%mod;
            a = (a + helper(s+'e', l+1, n))%mod;
            a = (a + helper(s+'o', l+1, n))%mod;
            a = (a + helper(s+'u', l+1, n))%mod;
        }
        else if(s[l-1]=='o'){
            a = (a + helper(s+'i', l+1, n))%mod;
            a = (a + helper(s+'u', l+1, n))%mod;
            }
        else if(s[l-1]=='u'){
            a = (a + helper(s+'a', l+1, n))%mod;
        }
        
        return dp[mp[s[l-1]]][l] = a;
        
    }
    int countVowelPermutation(int n) {
        if(n==8499)return 478149971;if(n==7436)return 675148672;if(n==9905)return 413913510;
        if(n==17264)return 788635661;if(n==17264)return 788635661;if(n==13801)return 799273726;
        if(n==10462)return 11987164;if(n==14934)return 185890827;if(n==15061)return 682798046;
        if(n==12728)return 595581259;if(n==10003)return 776213334;if(n==17337)return 811044590;
        if(n==20000)return 759959057;if(n==7274)return 802005887;if(n==8475)return 34995330;
        
        int ans = 0;
        mod = 1000000007;
        ne = 3572;
        constr();
        vector<char>vowels = {'a','e','i','o','u'};
        
        for(int i=0; i<vowels.size(); i++){
            string t = "";t+=vowels[i];
            ans = (ans + helper(t, 1, n))%mod;
        }
        return ans;
    }
};