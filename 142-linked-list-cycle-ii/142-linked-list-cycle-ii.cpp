/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode*>arr;
        
        ListNode*temp = head;
        
        while(temp != NULL){
            bool bol = true;
            for(int i = 0; i<arr.size(); i++){
                if(arr[i] == temp){
                    return arr[i];
                }
                else{
                    bol = true;
                }
            }
            
            if(bol){
                arr.push_back(temp);
                temp = temp->next;
            }
        }
        
        return NULL;
        
        
    }
};