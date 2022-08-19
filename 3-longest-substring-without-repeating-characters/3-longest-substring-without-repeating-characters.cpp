class Solution {
public:
    int max(int a, int b){
        return (a>b)?a:b;
    }
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 1)
            return 1;
        int count = 0;
        unordered_map<char, int>mp;

        for(int i = 0; i<s.size(); i++){
            for(int j = i; j<s.size(); j++){
                if (mp.find(s[j]) != mp.end()){
                    break;
                }
                mp[s[j]]++;
            }
            count = max(mp.size(), count);  
            mp.clear();
        }
        return count;
    }
};