class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int>pq;
        for(int i=0; i<nums.size(); i++){
            pq[nums[i]]++;
        }
        int count = 0;
        for(auto &i: pq){
            nums[count++] = i.first;
        }
        return count;
        
    }
};