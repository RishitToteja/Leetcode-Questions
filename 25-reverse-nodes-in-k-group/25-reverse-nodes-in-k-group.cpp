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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1){
            return head;
        }
        vector<int>arr;
        ListNode*temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        if(arr.size() == k){
            ListNode*si = NULL;
            ListNode*ei = NULL;
            for(int i=arr.size()-1; i>=0; i--){
                ListNode*t = new ListNode(arr[i]);
                if(si == NULL){
                    si = t;
                    ei = t;
                }
                else{
                    ei->next = t;
                    ei = t;
                }
            }
            return si;
        }
        
        vector<int>ans;
        int i=0;
        for(; i<arr.size(); i+=k){
            if(i+k<arr.size()){
                for(int j = i+k-1; j>=i; j--){
                    ans.push_back(arr[j]);

                }
        }
            cout<<i<<endl;
        }
        if(arr.size()%k != 0){
            i -=k;
            for(; i<arr.size(); i++){
                ans.push_back(arr[i]);
            }
        }
        if(arr.size()%k == 0){
            i -=k;
            for(int j = arr.size()-1; j>=i; j--){
                ans.push_back(arr[j]);
            }
        }
        
        ListNode*si = NULL;
        ListNode*ei = NULL;
        
        for(int i=0; i<ans.size(); i++){
            ListNode*t = new ListNode(ans[i]);
            if(si == NULL){
                si = t;
                ei = t;
            }
            else{
                ei->next = t;
                ei = t;
            }
        }
        
        return si;
        
    }
};