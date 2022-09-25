class MyCircularQueue {
public:
    list<int>l;
    int size ;
    int curr ;
    MyCircularQueue(int k) {
        size=k;
        curr = 0;
        
    }
    
    bool enQueue(int value) {
        if(curr == size){
            return false;
        }
        l.push_back(value);
        curr++;
        return true;
    }
    
    bool deQueue() {
        if(curr==0)
            return false;
        l.pop_front();
        curr--;
        return true;
    }
    
    int Front() {
        if(curr==0)return -1;
        return l.front();
    }
    
    int Rear() {
        if(curr==0)return -1;
        return l.back();
    }
    
    bool isEmpty() {
        return curr==0;
    }
    
    bool isFull() {
        return curr == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */