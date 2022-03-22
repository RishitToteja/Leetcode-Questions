class Solution {
public:
    int minPartitions(string n) {
        vector<int>s;
        
        for(int i = 0; i<n.size(); i++){
            s.push_back(n[i] - '0');
        }
        
        int max = -1;
        
        for(int i = 0; i<s.size(); i++){
            if(s[i] > max){
                max = s[i];
            }
        }
        
        return max;
    }
};