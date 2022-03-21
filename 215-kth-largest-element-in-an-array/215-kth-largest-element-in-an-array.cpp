class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
//         vector<int>set;
        
//         for(int i = 0; i<nums.size(); i++){
//             bool bol = true;
//             for(int j = 0; j<set.size(); j++){
//                 if(set[j] == nums[i]){
//                     bol = false;
//                 }
//             }
            
//             if(bol)
//                 set.push_back(nums[i]);
//         }
        

        return nums[nums.size()-k];
    }
};