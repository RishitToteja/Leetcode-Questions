class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0)return 0;
        else{for(int i=0, j=s.size()-1; i<s.size(); i++, j--){if(s[i]!=s[j])return 2;}return 1;}
    }
};