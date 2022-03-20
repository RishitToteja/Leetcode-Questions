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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>arr;
        ListNode*temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        vector<int>news;
        
        for(int i = 0; i<left-1; i++){
            news.push_back(arr[i]);
        }
        for(int i = right-1; i>=left-1; i--){
            news.push_back(arr[i]);
        }
        for(int i = right; i<arr.size(); i++){
            news.push_back(arr[i]);
        }
        
        ListNode*si = NULL;
        ListNode*ei = NULL;  
        
        for(int i = 0; i<news.size(); i++){
            ListNode*te = new ListNode(news[i]);
            if(si == NULL){
                si = te;
                ei = te;
            }

            else{

                ei->next = te;
                ei = te;
                
            }
        }
        return si;
    }
};