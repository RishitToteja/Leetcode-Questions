class Solution {
public:
    string f(int a){
        bitset<8>b(a);
        string s = "";
        for(int j=7; j>=0; j--){
            s+=b[j]+'0';
        }
        return s;
    }
    bool validUtf8(vector<int>& data) {
        for(int i=0; i<data.size(); i++){
            string s = f(data[i]);
            cout<<s;
            if(s[0]=='0')
                continue;
            else if(s[0]=='1' && s[1]=='1' && s[2]=='0'){
                if(i+1<data.size()){
                    string t = f(data[i+1]);
                    if(t[0]=='1' && t[1]=='0'){
                        i+=1;
                    }
                    else
                        return false;
                }
                else{
                    return false;
                }
            }
            else if(s[0]=='1' && s[1]=='1' && s[2]=='1' && s[3]=='0'){
                if(i+2<data.size()){
                    string t = f(data[i+1]);
                    string t2 = f(data[i+2]);
                    if(t[0]=='1' && t[1]=='0' && t2[0]=='1' && t2[1]=='0'){
                        i+=2;
                    }
                    else
                        return false;
                }
                else{
                    return false;
                }
            }
            else if(s[0]=='1' && s[1]=='1' && s[2]=='1' && s[3]=='1' && s[4]=='0'){
                if(i+3<data.size()){
                    string t = f(data[i+1]);
                    string t2 = f(data[i+2]);
                    string t3 = f(data[i+3]);
                    if(t[0]=='1' && t[1]=='0' && t2[0]=='1' && t2[1]=='0' && t3[0]=='1' && t3[1]=='0'){
                        i+=3;
                    }
                    else
                        return false;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};