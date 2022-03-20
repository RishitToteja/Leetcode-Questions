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
    
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int>arr;
        ListNode*temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        sort(arr.begin(), arr.end());
        
        vector<int>set = {};
        
        for(int i = 0; i<arr.size(); i++){
            int count = 0;
            for(int j = 0; j<arr.size(); j++){
                if(arr[j] == arr[i]){
                    count++;
                }
            }
            cout<<count<<endl;
            if(count==1){
                set.push_back(arr[i]);
            }
        }
        
        ListNode*si = NULL;
        ListNode*ei = NULL;  
        
        for(int i = 0; i<set.size(); i++){
            ListNode*te = new ListNode(set[i]);
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