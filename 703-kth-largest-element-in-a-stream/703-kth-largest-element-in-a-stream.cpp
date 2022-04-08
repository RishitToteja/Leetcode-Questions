class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        if(nums.size() == 0){
            pq.push(INT_MIN);
        }
        else if(nums.size() > k){
            for(int i=0; i<k; i++){
                pq.push(nums[i]);
            }
            for(int i=k; i<nums.size(); i++){
                if(pq.top()<nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        
        else if(nums.size() <= k){
            for(int i=0; i<nums.size(); i++){
                pq.push(nums[i]);
            }
        }
        
    }
    
    int add(int val) {
        if(pq.size() < k){
            pq.push(val);
            return pq.top();
        }
        if(pq.top() < val){
            pq.pop();
            pq.push(val);
            return pq.top();
        }
        else{
            return pq.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */