class Solution {
public:

    string removeOccurrences(string s, string part) {
        
        string s1 = s;
        while(s1.find(part) < s1.length()){
            s1.erase(s1.find(part), part.size());    
        }
        return s1;
        
    }
        
};