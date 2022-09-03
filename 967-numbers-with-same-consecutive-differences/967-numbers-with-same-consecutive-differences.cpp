class Solution {
public:
    map<int, int>mp;
    vector<int>arr;
    void helper(string s, int n, int k){
        
        if(s.size()==n){
            int temp = stoi(s);
            if(mp.find(temp)==mp.end()){
                mp[temp]++;
                arr.push_back(temp);
            }
            return ;
        }
        
        if(s.size()<n){
            char last = s[s.size()-1];
            int end = last-'0';
            if(end+k<=9){
                string t = s;
                t.push_back(end+k+'0'); 
                helper(t, n, k);
            }
            if(end-k>=0){
                string t = s;
                t.push_back(end-k+'0'); 
                helper(t, n, k);
            }
        }
        return ;
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1; i<10; i++){
            helper(to_string(i), n, k);
        }
        return arr;
    }
};