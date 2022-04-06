class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        sort(arr.begin(), arr.end());
        
        unordered_map<int, int> mp;//num, freq
        
        int count = 0;
        int mod = 1000000007;
        
        for (int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        
        for (int i=0; i<arr.size()-2; i++){
            
            int sum = target - arr[i];
            
            mp[arr[i]]--;
            
            int left = i+1;
            int right = arr.size()-1;
            
            while(left < right){
                
                int mysum = arr[left] + arr[right];
                
                if (mysum > sum) right -= mp[arr[right]];
                else if (mysum < sum) left += mp[arr[left]];
                else{
                    
                    if (arr[left] == arr[right]){
                        int n = right - left + 1;
                        count = (count + (n*(n-1))/2)%mod;
                        break;
                    }
                    
                    count = (count + mp[arr[left]]*mp[arr[right]])%mod;
                    left += mp[arr[left]];
                    right -= mp[arr[right]];  
                }
            }
        }
        
        return count;
        
    }
};