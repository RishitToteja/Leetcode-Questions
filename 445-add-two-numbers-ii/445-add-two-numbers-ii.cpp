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
        
        ListNode*temp1 = l1;
        ListNode*temp2 = l2;
        
        vector<int>v1;
        vector<int>v2;
        
        while(temp1 != NULL){
            v1.push_back(temp1->val);
            temp1 = temp1->next;
        }
        
        while(temp2 != NULL){
            v2.push_back(temp2->val);
            temp2 = temp2->next;
        }
        
        
        vector<int>news;
        
        if(v1.size() < v2.size()){
            int carry = 0;
            int o = v2.size() - 1;
            for(int i = v1.size()-1; i>=0 ; i--, o--){
                int t = v1[i] + v2[o] + carry;
                if(t>9){
                    news.push_back(t%10);
                    carry = (t - (t%10))/10;
                }    
                else{
                    news.push_back(t);
                    carry = 0;
                }
            }
            

            for(int i = v2.size() - v1.size() - 1; i>=0 ; i--){
                int t = v2[i] + carry;
                if(t>9){
                    news.push_back(t%10);
                    carry = (t - (t%10))/10;
                }    
                else{
                    news.push_back(t);
                    carry = 0;
                }
            }
            
            if(carry != 0){
                news.push_back(carry);
            }
        }
        
        else{
            int carry = 0;
            int o = v1.size() -1;
            for(int i = v2.size()-1; i>=0 ; i--, o--){
                int t = v1[o] + v2[i] + carry;
                if(t>9){
                    news.push_back(t%10);
                    carry = (t - (t%10))/10;
                }    
                else{
                    news.push_back(t);
                    carry = 0;
                }
            }
            
            
            
          
            for(int i = v1.size() - v2.size() - 1; i>=0 ; i--){
         
                int t = v1[i] + carry;
                if(t>9){
                    news.push_back(t%10);
                    carry = (t - (t%10))/10;
                }    
                else{
                    news.push_back(t);
                    carry = 0;
                }
            }
            
            if(carry != 0){
                news.push_back(carry);
            }
        }
        
        ListNode*si = NULL;
        ListNode*ei = NULL;
        
        for(int i = news.size() - 1; i>=0; i--){
            ListNode*temp = new ListNode(news[i]);
            if(si == NULL){
                si = temp;
                ei = temp;
            }
            
            else{
                ei->next = temp;
                ei = temp;
            }
        }
        for(int i = 0; i<news.size(); i++){
            cout<<news[i]<<" ";
        }
        
        return si;
        
    }
};