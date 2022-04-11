class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int count=0;
        
        vector<vector<int>>ret;
        while(count!=k){
            vector<vector<int>>temp;
            for(int i=0; i<grid.size(); i++){
                vector<int>t= grid[i];
                vector<int>a = {t[t.size()-1]};
                for(int j=0; j<t.size()-1; j++){
                    a.push_back(t[j]);
                }
                temp.push_back(a);
            }
            vector<int>first;
            
            for(vector<int>i: temp){
                first.push_back(i[0]);
            }
            
            vector<int>fn  = {first[first.size()-1]};
            for(int i=0; i<first.size()-1; i++){
                fn.push_back(first[i]);
            }
            
            int j = 0;
            for(int i = 0; i<temp.size();i++){
                temp[i][0] = fn[j];
                j++;
            }
                                    
            
            grid = temp;  
                                  
                                   
            
            count++;
        }
       
        return grid;
        
    }
};