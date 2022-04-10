#include <unordered_map>
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        vector<int>ans(k);
        for(int i=0; i<k; i++){
            ans[i] = 0;
        }
        unordered_map<int, vector<int>>pq;
        
        for(int i=0; i<logs.size(); i++){
            pq[logs[i][0]].push_back(logs[i][1]);
        }
        unordered_map<int,int>pq2;
        
        for(auto &i: pq){
            
            vector<int>vec = i.second;
            sort( vec.begin(), vec.end() );
            vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
            
            pq2[i.first] = vec.size();
            ans[pq2[i.first]-1]++;
            cout<<i.first<<" "<<pq2[i.first]<<endl;
        }
        
        return ans;
    }
};