class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){return (a[1]<b[1]);}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),comp);
        
        int curr = pairs[0][1];
        int cnt = 1;
        for(int i=1; i<pairs.size(); i++){
            if(pairs[i][0]>curr){
                cnt++;
                curr = pairs[i][1];
            }
        }
        return cnt;
    }
};