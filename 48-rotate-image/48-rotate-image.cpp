class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>a;
        for(int i=0; i<matrix.size(); i++){
            vector<int>t;
            for(int j=matrix.size()-1; j>=0; j--){
                t.push_back(matrix[j][i]);
            }
            a.push_back(t);
        }
        matrix=a;
    }
};