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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>arr1;
        ListNode*temp = l1;
        while(temp != NULL){
            arr1.push_back(temp->val);
            temp = temp->next;
        }
        
        vector<int>arr2;
        temp = l2;
        while(temp != NULL){
            arr2.push_back(temp->val);
            temp = temp->next;
        }
        
        vector<int>sum;
        
        if(arr1.size() < arr2.size()){
            int carry = 0;
            int j = 0;
            for(int i = 0; i<arr1.size(); i++, j++){
                int temp = arr1[i] + arr2[j] + carry;
                if(temp>9){
                    sum.push_back(temp%10);
                    carry = (temp-(temp%10))/10;
                }
                else{
                    sum.push_back(temp);
                    carry = 0;
                }
            }
            
            for(int i = j; i<arr2.size(); i++){
                
                int temp = arr2[i] + carry;
                if(temp>9){
                    sum.push_back(temp%10);
                    carry = (temp-(temp%10))/10;
                }
                else{
                    sum.push_back(temp);
                    carry = 0;
                }
                
            }
            
            if(carry != 0){
                sum.push_back(carry);
            }
        }
        
        else{
            int carry = 0;
            int j = 0;
            for(int i = 0; i<arr2.size(); i++, j++){
                int temp = arr2[i] + arr1[j] + carry;
                if(temp>9){
                    sum.push_back(temp%10);
                    carry = (temp-(temp%10))/10;
                }
                else{
                    sum.push_back(temp);
                    carry = 0;
                }
            }
            
            for(int i = j; i<arr1.size(); i++){
                
                int temp = arr1[i] + carry;
                if(temp>9){
                    sum.push_back(temp%10);
                    carry = (temp-(temp%10))/10;
                }
                else{
                    sum.push_back(temp);
                    carry = 0;
                }
                
            }
            
            if(carry != 0){
                sum.push_back(carry);
            }
        }
        
        for(int i = 0; i<sum.size(); i++){
            cout<<sum[i]<<" ";
        }
        
        ListNode*si = NULL;
        ListNode*ei = NULL;  
        
        for(int i = 0; i<sum.size(); i++){
            ListNode*te = new ListNode(sum[i]);
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