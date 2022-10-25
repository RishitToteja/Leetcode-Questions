class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        vector<long long>arr;
        for(int i=1; i<=n; i++){
            arr.push_back(i);
        }
        for(int i=1; i<arr.size(); i++){
            arr[i]+=arr[i-1];
        }
        return upper_bound(arr.begin(), arr.end(), n)-arr.begin();
        
    }
};