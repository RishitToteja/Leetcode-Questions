class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>>ans;
        for(int i=0; i<arr.size(); i++){
            ans.push_back({abs(arr[i]-x), arr[i]});
        }
        sort(ans.begin(), ans.end());
        
        vector<int>ret;
        for(int i=0; i<k; i++){
            ret.push_back(ans[i].second);
        }
        sort(ret.begin(), ret.end());
        
        return ret;
    }
};


