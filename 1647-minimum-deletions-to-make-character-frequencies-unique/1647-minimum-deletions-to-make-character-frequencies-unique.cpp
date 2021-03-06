class Solution {
public:
    pair<bool,char> check(unordered_map<char, int>pq){
        unordered_map<int, vector<char>>m;
        for(auto&i: pq){
            m[i.second].push_back(i.first);
        }
        for(auto&i: m){
            if(i.second.size()>1)
                return {false,i.second[0]};
        }
        return {true, '0'};
    }
    int minDeletions(string s) {
        unordered_map<char, int>pq;
        for(char i: s){
            pq[i]++;
        }
        int count = 0;
        while(true){
            pair<bool,char>t = check(pq);
            if(t.first)
                break;
            pq[t.second]--;
            if(pq[t.second]==0)
                pq.erase(t.second);
            count++;
        }
        return count;
    }
};