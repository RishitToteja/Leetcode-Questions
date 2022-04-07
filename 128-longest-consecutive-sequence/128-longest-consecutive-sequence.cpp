#include <unordered_map>
#include <algorithm>
#include <climits>
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_map<int, int>pq;
        for(int i=0; i<arr.size(); i++){
            pq[arr[i]]++;
        }
        arr = {};
        
        for (auto& it: pq){
            arr.push_back(it.first);
        }
        if(arr.size() == 0){
            return 0;
        }
        sort(arr.begin(), arr.end());
        vector<int>c;
        
        int count = 0;
        
        for(int i=1; i<arr.size(); i++){
            //cout<<arr[i]<<" ";
            if(arr[i] == arr[i-1]+1){
                count++;
            }
            else{
                c.push_back(count);
                count = 0;
            }
        }
        c.push_back(count);
    
        return *max_element(c.begin(), c.end())+1;
    }
};