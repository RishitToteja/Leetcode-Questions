class Solution {
private:
    vector<int>mem;
    priority_queue<pair<int,int>>pq;
    int solve(vector<int>&nums,int index,int k){
        int n=nums.size();
        if(index==n-1){
            pq.push(make_pair(nums[index],index));
            return nums[index];
        } else if(mem[index]!=-1){
            pq.push(make_pair(mem[index],index));
            return mem[index];
        } else {
            solve(nums,index+1,k);
            while(!pq.empty()){
                int score=pq.top().first;
                int idx=pq.top().second;
                if(idx-index<=k){
                    mem[index]=nums[index]+score;
                    pq.push(make_pair(mem[index],index));
                    break;
                } else {
                    pq.pop();
                }
            }
            return mem[index];
        }
    }
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        mem=vector<int>(n,-1);
        return solve(nums,0,k);
    }
};