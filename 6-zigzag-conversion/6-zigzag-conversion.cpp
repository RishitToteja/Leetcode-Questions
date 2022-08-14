class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        char **arr = new char*[numRows];
        for(int i=0; i<numRows; i++){
            arr[i]=new char[s.size()];
            for(int j=0; j<s.size(); j++){
                arr[i][j]= '-';
            }
        }
        int si = 0;
        int t = 0;
        while(si<s.size()){
            for(int i=0; i<numRows; i++){
                if(si<s.size())
                    arr[i][t] = s[si++];
            }
            t++;
            for(int j=numRows-2;j>=1; j--){
                if(si<s.size())
                    arr[j][t++] = s[si++];
            }
            // for(int i=0; i<numRows; i++){
            //     for(int j=0; j<s.size(); j++){
            //         cout<<arr[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
        }
        
        
        for(int i=0; i<numRows; i++){
            for(int j=0; j<s.size(); j++){
                if(arr[i][j]!='-')
                    ans += arr[i][j];
            }
        }
        
        return ans;
        
    }
};