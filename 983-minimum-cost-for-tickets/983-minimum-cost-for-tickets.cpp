class Solution {
public:
    vector<int>arr = {1, 7, 30};
    int dp[366];
    int helper(vector<int>&days, vector<int>&costs, int idx){

        if(idx >= days.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        
        int cost = INT_MAX;
        
        for(int j=0; j<costs.size(); j++){
            int max_day = days[idx]+ arr[j]-1;
            int last = upper_bound(days.begin(), days.end(), max_day)-days.begin();
            cost = min(cost, costs[j]+helper(days, costs, last));
        }
        return dp[idx]=cost;
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        
        return helper(days, costs, 0);
    }
};
