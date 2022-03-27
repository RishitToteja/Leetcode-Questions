class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>cnt;
        
       for(vector<int>i: mat){
           int count = 0;
           for(int j: i){
               if(j==1){
                   count++;
                   }
          
    }
           cnt.push_back(count);
   }
        vector<int>ans;
        for(int i = 0; i<cnt.size(); i++){
            cout<<cnt[i]<<" ";
        }
        
        
        while(ans.size()!=k){
            pair<int,int>min;
            min.first = 0;
            min.second = cnt[0];
            
            for(int i=1; i<cnt.size(); i++){
                if(cnt[i]<min.second){
                    min.first = i;
                    min.second = cnt[i];
                }
            }
            ans.push_back(min.first);
            cnt[min.first] = INT_MAX;
        }





        return ans;
    }
};