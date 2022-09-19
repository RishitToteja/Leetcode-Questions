class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int m = INT_MIN;
        map<int, int>mp;
        int sum = 0;
        int j=0;
        for(int i=0; i<arr.size(); i++){
            if(mp.size()==2){
                if(mp.find(arr[i])==mp.end()){  
                    m = max(m, sum);
                    sum --;
                    mp[arr[j]]--;
                    if(mp[arr[j]]==0)
                        mp.erase(arr[j]);
                    j++;
                    i--;
                    continue;
                }
                else{
                    mp[arr[i]]++;
                    sum += 1;
                }
            }
            else{
                mp[arr[i]]++;
                sum +=1;
            }
        }
        return max(m, sum);
    }
    
};