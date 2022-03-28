class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        
        int count = 0;
        while(true){
            int a1 = pq.top();
            pq.pop();
            int a2 = pq.top();
            pq.pop();
            int a3 = pq.top();
            
            
            pq.push(a1-1);
            pq.push(a2-1);
            //pq.push(a3);

            if(a2 == 0 && a3 == 0){
                break;
            }
            count++;
        }
        
        return count;
    }
};