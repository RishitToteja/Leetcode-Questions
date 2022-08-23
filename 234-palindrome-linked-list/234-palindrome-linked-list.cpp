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

// si = 1, prev = NULL -> NULL<-1
// 

class Solution {
public:
    ListNode* rev(ListNode*s, ListNode*prev){
        ListNode*si = new ListNode(s->val);
        while(s ->next != NULL){
            ListNode*temp = new ListNode(s->next->val);
            si->next = prev;
            prev = si;
            si = temp;
            s = s->next;
        }
        si->next = prev;
        return si;

    }
        
    bool isPalindrome(ListNode* head) {
        ListNode*r = rev(head, NULL);
        while(r!=NULL&&head!=NULL){
            if(r->val != head->val)
                return false;
            r = r->next;
            head = head->next;
        }
        return true;
    }
};