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
    vector<ListNode*> splitListToParts(ListNode* head, int k){
        if(head == NULL){
            vector<ListNode*>a;
            for(int i = 0; i<k; i++){
                a.push_back(NULL);
            }
            return a;
        }
    vector<ListNode*> res;
    if(!head) return res;
    int len = 0;
    ListNode* cur = head;
    while(cur){
        len++;
        cur = cur->next;
    }
    int part_len = len / k;
    int remain = len % k;
    cur = head;
    for(int i = 0; i < k; i++){
        ListNode* part = new ListNode(0);
        ListNode* cur_part = part;
        int count = part_len + (remain-- > 0);
        while(count--){
            cur_part->next = new ListNode(cur->val);
            cur_part = cur_part->next;
            cur = cur->next;
        }
        res.push_back(part->next);
    }
    return res;
}
};