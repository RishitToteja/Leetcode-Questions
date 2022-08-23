class Solution {
public:
    vector<vector<int>>arr;
    void adobe(int row, int col){
        for(int i=0; i<arr[0].size(); i++){
            arr[row][i]=0;
        }
        for(int i=0; i<arr.size(); i++){
            arr[i][col]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        arr = matrix;
       for(int i=0; i<matrix.size(); i++){
           for(int j=0; j<matrix[0].size(); j++){
               if(matrix[i][j]==0)
                   adobe(i, j);
           }
       }
        matrix = arr;
        return ;
    }
};