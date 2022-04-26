class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int>pq;
        
        vector<int>ans;
        
        for(int i=0; i<numbers.size(); i++){
            pq[numbers[i]] = i;
        }
        for(int i=0; i<numbers.size(); i++){
            int rem = target - numbers[i]; //i;
            if(pq[rem] != 0 && i != pq[rem]){
                ans.push_back(i);
                ans.push_back(pq[rem]);
                break;
            }
            
            if(pq[rem] == 0 && rem == numbers[0] && i != pq[rem]){
                ans.push_back(i);
                ans.push_back(pq[rem]);
                break;
        }
    }

        return ans;
    }
        
};