class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char, int>mp;

        for(int i=0; i<words2.size(); i++){
            map<char, int>pq;
            for(int j=0; j<words2[i].size(); j++){
                pq[words2[i][j]]++;
            }
            for(auto it: pq){
                if(mp.find(it.first)!=mp.end()){
                    mp[it.first] = max(mp[it.first], it.second);
                }
                else{
                    mp[it.first]=it.second;
                }
            }
        }
        vector<string>ans;
        for(int i=0; i<words1.size(); i++){
            map<char, int>pq;
            for(int j=0; j<words1[i].size(); j++){
                pq[words1[i][j]]++;
            }
            bool bol = true;
            for(auto it: mp){
                if(pq.find(it.first)==pq.end() || it.second>pq[it.first]){
                    bol = false;
                    break;
                }
            }
            if(bol)
                ans.push_back(words1[i]);
        }
        
        return ans;
    }
};