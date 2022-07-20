class Solution {
public:    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map<char, vector<int>>pq;
        for(int i=0; i<s.size(); i++){
            pq[s[i]].push_back(i);
        }
        
        for(int i=0; i<words.size(); i++){
            string str = words[i];
            if(pq.find(str[0]) == pq.end()){
                continue;
            }
            else{
                bool bol = true;
                int t;
                t = pq[str[0]][0];
                for(int j=1; j<str.size(); j++){
                    if(pq.find(str[j]) != pq.end()){
                        int last = t;
                        vector<int>thi = pq[str[j]];
                        auto it = upper_bound(thi.begin(), thi.end(), last);
                        if(it==thi.end())
                            bol = false;
                        else
                            t = *it;
                        if(!bol)
                            break;   
                    }
                    else
                        bol = false;
                }
                if(bol){
                    count++;
                }
                
            }
            
            
        }
        
        return count;
    }
};