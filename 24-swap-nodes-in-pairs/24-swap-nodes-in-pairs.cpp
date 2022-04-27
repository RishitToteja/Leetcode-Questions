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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        
        else{
            ListNode*nh = head->next;
            ListNode*temp = nh->next;
            nh->next = head;
            head->next = swapPairs(temp);
            
            return nh;
            
        }
    }
};