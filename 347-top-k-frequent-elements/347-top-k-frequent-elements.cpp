class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        pair<int, int>p;
        p.first = nums[0];
        p.second = 1;
        
        vector<pair<int, int>>a;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == p.first){
                p.second++;
            }
            else{
                pair<int, int>temp;
                temp.first = p.first;
                temp.second = p.second;
                a.push_back(temp);
                p.first = nums[i];
                p.second = 1;
            }
        }
        a.push_back(p);
        for(int i = 0; i<a.size(); i++){
            cout<<a[i].first<<": "<<a[i].second;
            cout<<endl;
        }
        vector<int>ans;
        
        while(k--){
            pair<int, int>d;
            d.first = a[0].first;
            d.second = a[0].second;
            int ind = 0;
            for(int i = 1; i<a.size(); i++){
                if(a[i].second > d.second){
                    d.first = a[i].first;
                    d.second = a[i].second;
                    ind = i;
                }
            }
            ans.push_back(d.first);
            a[ind].second = -1;
        }
        return ans;
    }
};