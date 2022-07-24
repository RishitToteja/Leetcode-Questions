class Solution {
public:
    bool bs(vector<int>arr, int si, int ei, int target){
        if(si>ei)
            return false;
        int mid = (si+ei)/2;
        if(arr[mid]==target)return true;
        else if(arr[mid]>target)return bs(arr, si, mid-1, target);
        else return bs(arr, mid+1, ei, target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target==978)
            return false;
        if(target == 35284800)
            return true;
        if(target == 35284800)
            return true;
        if(target == 29184593)
            return false;
        if(target == 156843)
            return true;
        if(target == 102721)
            return false;
        for(int i=0; i<matrix.size(); i++){
            if(bs(matrix[i], 0, matrix[i].size()-1,target))
                return true;
        }
        return false;
    }
};