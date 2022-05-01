class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>end;
        
        int s = matrix[0].size();
        for(int i = 0; i<matrix.size(); i++){
            vector<int>temp = matrix[i];
            end.push_back(temp[s-1]);
        }
        
        
        vector<int>temp;
        
        for(int i = 0; i<end.size(); i++){
            cout<<end[i];
            if(target<=end[i]){
                temp = matrix [i];
                break;
            }
                //temp = matrix[i];
                //break;
        }
        
        
        
        for(int i : temp)
            if(i==target)
             return true;


        
        return false;

        
    }
};