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
    void reorderList(ListNode* head) {
        vector<int>arr;
        ListNode*temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        vector<int>news;
        int i = 0;
        int j = arr.size()-1;
        
        for(int k = 0; k<arr.size(); k++){
            if(k%2 == 0){
                news.push_back(arr[i]);
                news.push_back(arr[j]);
                j--;
                i++;
            }

        }
        
        ListNode*si = NULL;
        ListNode*ei = NULL;  
        
        for(int i = 0; i<news.size(); i++){
            cout<<news[i]<<" ";
        }
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
        //ListNode*temp1 = head;
        
        while(head!=NULL){
            head->val = si->val;
            head = head->next;
            si = si->next;
        }
        
        
        
    }
};