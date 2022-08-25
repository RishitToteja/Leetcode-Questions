class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>m(bank.size(), 0);
        for(int i=0; i<bank.size(); i++){
            for(int j=0; j<bank[i].size(); j++){
                if(bank[i][j]=='1')
                    m[i]++;
            }
        }
        vector<int>arr;
        for(int i=0; i<m.size(); i++){
            if(m[i]!=0)
                arr.push_back(m[i]);
        }
        
        int ans = 0;
        for(int i=1; i<arr.size(); i++){
            //cout<<arr[i]<<" ";
            ans += arr[i-1]*arr[i];
        }
        return ans;
        
    }
};