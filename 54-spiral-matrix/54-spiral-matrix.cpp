class Solution {
public:
    void spiralTraverse(vector<vector<int>>&matrix, vector<int>&spiralTraversal, int i_cur, int j_cur, int m, int n){
        if(i_cur==matrix.size() || j_cur == matrix[0].size())
            return ;
        for(int i=j_cur; i<n; i++){
            if(matrix[i_cur][i]!=INT_MIN){
                spiralTraversal.push_back(matrix[i_cur][i]);
                matrix[i_cur][i]=INT_MIN;
             }
        }
        for(int i=i_cur+1; i<m; i++){
            if(matrix[i][n-1]!=INT_MIN){
                spiralTraversal.push_back(matrix[i][n-1]);
                matrix[i][n-1]=INT_MIN;
             }
        }
        for(int i=n-2; i>=j_cur; i--){
            if(matrix[m-1][i] != INT_MIN){
                spiralTraversal.push_back(matrix[m-1][i]);
                matrix[m-1][i]=INT_MIN;
             }
        }
        for(int i=m-2; i>i_cur; i--){
            if(matrix[i][i_cur] != INT_MIN){
                spiralTraversal.push_back(matrix[i][i_cur]);
                matrix[i][i_cur]=INT_MIN;
             }
        }
        for(int i: spiralTraversal){
            cout<<i<<" ";
        }
        cout<<endl;
        spiralTraverse(matrix, spiralTraversal, i_cur+1, j_cur+1, m-1, n-1);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>spiralTraversal;
        spiralTraverse(matrix, spiralTraversal, 0, 0, matrix.size(), matrix[0].size());
        return spiralTraversal;
    }
};