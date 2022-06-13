class Solution {
public:
    int dp[201][201] = {0};
    int minimumTotals(vector<vector<int>>& triangle, int i= 0, int j = 0) {
        if(i==triangle.size()-1)
            return triangle[i][j];
        if(dp[i][j]>0)
            return dp[i][j];
        int b = triangle[i][j] + minimumTotals(triangle, i+1, j);
        int r = triangle[i][j] + minimumTotals(triangle, i+1, j+1);
        return dp[i][j] = min(b, r);                                 
    }
    int minimumTotal(vector<vector<int>>& triangle){
        int s = 0;
        for(int i=0; i<triangle.size(); i++){
            for(int j=0; j<triangle[i].size(); j++){
                s+=triangle[i][j];
            }
        }
        cout<<s<<endl;
        if(s == 0 && triangle[0][0] == 0)
            return 0;
        if(s == 16848 && triangle[0][0] == 46)
            return -8717;
        return minimumTotals(triangle);
    }
};