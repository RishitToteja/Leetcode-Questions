/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL|| head->next==NULL)
            return head;
        ListNode*si = NULL;
        ListNode*ei = NULL;
        
        ListNode*temp = head;
        
        while(temp!=NULL){
            if(temp->val < x){
                ListNode*node = new ListNode(temp->val);
                if(si == NULL){
                    si = node;
                    ei = node;
                }
                else{
                    ei->next = node;
                    ei = node;
                }
            }
            temp = temp->next;
            
        }
        ListNode*si2 = NULL;
        ListNode*ei2 = NULL;
        
        temp = head;
        
        while(temp!=NULL){
            if(temp->val >= x){
                ListNode*node = new ListNode(temp->val);
                if(si2 == NULL){
                    si2 = node;
                    ei2 = node;
                }
                else{
                    ei2->next = node;
                    ei2 = node;
                }
            }
            temp = temp->next;
            
        }
        if(ei==NULL)
            return si2;
        ei->next = si2;
        return si;
        
        
    }
};