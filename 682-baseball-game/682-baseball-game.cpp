using namespace std;
#include<iostream>
#include<string>
class Solution {
public:
    
    int calPoints(vector<string>& ops) {
        
        stack<int>ans;
        
        for(int i = 0; i<ops.size(); i++){
                       
            
            if(ops[i] == "C"){
                ans.pop();
            }
            else if(ops[i] == "D"){
                ans.push(2*ans.top());
            }
            else if(ops[i] == "+"){
                int prev_1 = ans.top();
                ans.pop();
                int prev_2 = ans.top();
                int n = prev_1 + prev_2;
                ans.push(prev_1);
                ans.push(n);
            }
            
            else{
                ans.push(stoi(ops[i]));
            }
        }
        
        int ret = 0;
        
        while(!ans.empty()){
            ret += ans.top();
            ans.pop();
        }
        
        return ret;
    }
};