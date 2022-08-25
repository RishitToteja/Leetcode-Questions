class Solution {
public:
    vector<vector<int>>arr;
   
    vector<int> getRow(int rowIndex) {
        int idx = rowIndex;
        arr.push_back({1});
        
        while(rowIndex>0){
            vector<int>temp = arr[arr.size()-1];
            vector<int>n(temp.size()+1, -1);
            n[0]=1;
            for(int i=1; i<temp.size(); i++){
                n[i] = (temp[i-1]+temp[i]);
            }
            n[temp.size()]=1;
            arr.push_back(n);
            rowIndex--;
        }
        
        return arr[idx];
    }
};