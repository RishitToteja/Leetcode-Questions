class Solution {
public:
    vector<int>dp;
    Solution(){
        for(int i=0; i<301; i++){
            dp.push_back(-1);
        }
    }
    bool helper(string s, unordered_map<string, int>wordMap) {
        if(wordMap[s]>0){
            dp[s.size()]=1;
            return true;
        }
        if(dp[s.size()]==1)
            return true;
        if(dp[s.size()]==0)
            return false;
        string sub_string = "";
        for(int i=0; i<s.size(); i++){
            if(wordMap[sub_string]>0){
                bool ans = helper(s.substr(sub_string.size()), wordMap);
                if(ans){
                    dp[s.size()]=1;
                    return true;
                }
            }
            sub_string += s[i];
        }
        dp[s.size()] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict){
        unordered_map<string, int>wordMap;
        
        for(string word: wordDict){
            wordMap[word]++;
        }
        return helper(s, wordMap);
    }
};