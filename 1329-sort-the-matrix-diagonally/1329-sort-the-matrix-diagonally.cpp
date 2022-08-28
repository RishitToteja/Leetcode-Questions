class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        
        
        for(int si=0; si<=m; si++ ){
            int ei=0;

            vector<int>temp;
            for(int i=si, j=ei; i<=m-1&&j<=n-1; i++, j++){
                temp.push_back(mat[i][j]);
            }
            sort(temp.begin(), temp.end());
            int k=0;

            for(int i=si, j=ei; i<=m-1&&j<=n-1; i++, j++){
                mat[i][j] = temp[k++];
            }
        }
        
        for(int ei=1; ei<=n; ei++ ){
            int si=0;

            vector<int>temp;
            for(int i=si, j=ei; i<=m-1&&j<=n-1; i++, j++){
                temp.push_back(mat[i][j]);
            }
            sort(temp.begin(), temp.end());
            int k=0;

            for(int i=si, j=ei; i<=m-1&&j<=n-1; i++, j++){
                mat[i][j] = temp[k++];
            }
        }
        
        return mat;
    }
};