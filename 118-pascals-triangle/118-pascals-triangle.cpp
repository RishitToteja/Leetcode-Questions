class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>a;
        a.push_back({1});
        if(numRows==1)
            return a;
        a.push_back({1, 1});
        for(int i=3; i<=numRows; i++){
            vector<int>t;
            vector<int>last = a[a.size()-1];
            t.push_back(1);
            
            for(int j=0; j<last.size()-1; j++){
                t.push_back(last[j]+last[j+1]);
            }
            
            t.push_back(1);
            a.push_back(t);
        }
        return a;
    }
};