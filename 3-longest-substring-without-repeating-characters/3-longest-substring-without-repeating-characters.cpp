class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char> chars;
        int ans = 0, i = 0, j = 0;
        while(i < n && j < n){
           
            if(chars.find(s[j]) == chars.end()){
                chars.insert(s[j]);
                ans = max(ans, j-i+1);
                j++;
            }
            else{
                chars.erase(s[i]);
                i++;
            }
        }
        
        return ans;
    }
};