class Solution {
public:
    int helper(vector<vector<int>>&matrix, int i, int j, int**arr, bool**vis){
        if(j<0 || j==matrix[0].size())
            return INT_MAX;
        
        if(i == matrix.size()-1){
            return matrix[i][j];
        }
        if(vis[i][j])
            return arr[i][j];
        int temp = matrix[i][j];
        int a = helper(matrix, i+1, j-1, arr, vis);
        int b = helper(matrix, i+1, j, arr, vis);
        int c = helper(matrix, i+1, j+1, arr, vis);
        vis[i][j]=true;
        
        return arr[i][j]=temp+min(a, min(b, c));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool**vis = new bool*[m];
        int**arr = new int*[m];
        for(int i=0; i<m; i++){
            vis[i]=new bool[n];
            arr[i]=new int[n];
            for(int j=0; j<n; j++){
                vis[i][j]=false;
                arr[i][j]=-1;
            }
        }
        
        
        for(int i=0; i<matrix[0].size(); i++){
            int count = helper(matrix, 0, i, arr, vis);
            ans = min(ans, count);
        }
        return ans;
    }
};