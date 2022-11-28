class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int, int>mp;
        
        for(int i=0; i<matches.size(); i++){
            mp[matches[i][0]]=0;
            mp[matches[i][1]]=0;
        }
        
        for(int i=0; i<matches.size(); i++){
            mp[matches[i][1]]++;
        }
        
        vector<int>a;
        vector<int>b;
        
        for(auto i:mp){
            if(i.second==1){
                b.push_back(i.first);
            }
            if(i.second==0){
                a.push_back(i.first);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        return {a,b};
        
    }
};