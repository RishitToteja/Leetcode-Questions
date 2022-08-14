class Solution {
public:
    string smallestNumber(string p) {
        string s = "123456789";
        for(int i=0; i<p.size(); i++){
            if(p[i]=='D'){
                int j=i;
                while(p[i]=='D')i++;
                reverse(s.begin()+j, s.begin()+i+1);
            }
        }
        return s.substr(0, p.size()+1);
    }
};