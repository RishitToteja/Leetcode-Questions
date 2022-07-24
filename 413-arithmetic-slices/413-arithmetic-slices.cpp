class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        
        vector<int>nums2;
        for(int i= 1; i<nums.size(); i++){
            int b = nums[i-1];
            int c = nums[i];
            nums2.push_back(c-b);
 
        }
        vector<int>high;
        vector<pair<int, int>>v = {{nums2[0], 1}};
        for(int i=1; i<nums2.size(); i++){
            if(v[v.size()-1].first == nums2[i])
                v.push_back({nums2[i], v[v.size()-1].second+1});
            else{
                high.push_back(v[v.size()-1].second);
                v.push_back({nums2[i], 1});
            }
        }
        if(v[v.size()-1].second>=2)
            high.push_back(v[v.size()-1].second);
        int ans = 0;
        
        for(int i=0; i<high.size(); i++){
            int n = high[i]+1;
            int t = n-3+1;
            ans += ((t*t)+t)/2;
            cout<<high[i]<<" ";
        }
        
        return ans;
    }
    
    // t = n-3+1
    // ((t*t)+t)/2
};