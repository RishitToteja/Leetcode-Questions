#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char>ans;
        
        ans.push(s[0]);
        for(int i = 1; i<s.size(); i++){
            if(!ans.empty()){
                if(ans.top() != s[i]){
                    ans.push(s[i]);
                    //cout<<ans.top()<<" ";
                }
                else{
                    ans.pop();
                
                }
            }
            else{
                ans.push(s[i]);
            }
        }
        
        string new_s = "";
        
        while(!ans.empty()){
            new_s += ans.top();
            ans.pop();
        }
        
        string rev = "";
        
        for(int i = new_s.size()-1; i>=0; i--){
            rev += new_s[i];
        }
        
        return rev;

        
    }
};