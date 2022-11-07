class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for(int i=0; i<s.size(); i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        int a = 0,x=0;
        for(int i=s.size()-1; i>=0; i--){
            a += (pow(10, x++))*(s[i]-'0');
        }
        return a;
    }
};