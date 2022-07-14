class MinStack {
private:
    stack<int> s;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    void push(int x) {
        s.push(x);
        pq.push(x);
    }
    
    void pop() {
        if (pq.top() == s.top()) pq.pop();
        else{
            vector<int>arr;
            int j=1;
            while(!pq.empty()){
                arr.push_back(pq.top());
                pq.pop();
            }
            for(int i=arr.size()-1; i>=0; i--){
                if(j==1 && arr[i]==s.top()){
                    j++;
                    continue;
                }
                else{
                    pq.push(arr[i]);
                }
            }
        }
        s.pop();
    }
    
    int top() { 
        return s.top(); 
    }
    int getMin() { 
        return pq.top(); 
    }
};