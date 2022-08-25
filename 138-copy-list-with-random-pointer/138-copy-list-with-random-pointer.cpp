/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;

        Node*temp = head;
        map<Node*, int>mp;
        while(temp!=NULL){
            mp[temp]++;
            Node*t = new Node(temp->val);
            t->next = temp->next;
            temp->next = t;
            temp = t->next;
        }
        
        temp = head;
        while(temp!=NULL){
            if(mp.find(temp) != mp.end()){
                if(temp->random != NULL)
                    temp->next->random = temp->random->next;
                else{
                    temp->next->random = NULL;
                }
            }
            temp = temp->next;
        }
        temp = head->next;
        // vector<Node*>arr;
        // arr.push_back(head);
        while(temp->next!=NULL){
            if(mp.find(temp->next)!=mp.end()){
                //arr.push_back(temp->next);
                temp->next = temp->next->next;
                temp = temp->next;
            }
        }
        temp = head->next;
        vector<Node*>arr;
        for(auto i: mp){
            arr.push_back(i.first);
        }
        int i=0;
        for(; i<arr.size()-1; i++){
            arr[i]->next = arr[i+1];
        }
        arr[i]->next = NULL;
        
        // while(temp!=NULL){
        //     if(temp->random!=NULL)
        //         cout<<temp->val<<" "<<temp->random->val<<endl;
        //     else
        //         cout<<temp->val<<" "<<"NULL"<<endl;
        //     temp = temp->next;
        // }
        return temp;
    }
};