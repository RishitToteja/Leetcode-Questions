class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int>s;
        for(int i = 0; i<boxes.size(); i++){
            s.push_back(boxes[i] - '0');
        }
        
        vector<int>ans;
        for(int i = 0; i<s.size(); i++){
            int count = 0;
            int it = 1;
            for(int j = i+1; j<s.size(); j++, it++){
                count += s[j]*it;
            }
            if(i!= 0){
                it = 1;
                for(int j = i-1; j>=0; j--, it++){
                    count += s[j]*it;
                }
            }
            
            ans.push_back(count);
            
        }
        
        return ans;
    }
};