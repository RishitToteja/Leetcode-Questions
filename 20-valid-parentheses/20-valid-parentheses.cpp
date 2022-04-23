#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char>pq;
        bool bol = false;
        
        int a1 = 0;
        int a2 = 0;
        
        int b1 = 0;
        int b2 = 0;
        
        int c1 = 0;
        int c2 = 0;
        
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                a1++;
            }
            if(s[i] == ')'){
                a2++;
            }
            if(s[i] == '{'){
                b1++;
            }
            if(s[i] == '}'){
                b2++;
            }
            if(s[i] == '['){
                c1++;
            }
            if(s[i] == ']'){
                c2++;
            }
        }
        if(a1!=a2 || b1!=b2 || c1!=c2)return false;
    
        
        if(s[0] == ')' || s[0] == '}' || s[0] == ']'){
                return false;
            }
        
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                
                pq.push(s[i]);
                bol = true;
            }
            
            if(s[i] == ')' && !pq.empty()){
                
                if(pq.top() == '('){
                    pq.pop();
                }
                //else if(c1 == 0)return false;
            }
            if(s[i] == '}' && !pq.empty()){
                
                if(pq.top() == '{'){
                    pq.pop();
                }
                //else if(c2 == 0)return false;
            }
            if(s[i] == ']' && !pq.empty()){
                
                if(pq.top() == '['){
                    pq.pop();
                }
                //else if(c3 == 0)return false;
            }
            
            
        }
        
    
        
        if(pq.size() != 0 || !bol){
            return false;
        }
        
        return true;
        
    }
};

// {[(])}

// ( [ {
// ) ] }

// (()[]{})