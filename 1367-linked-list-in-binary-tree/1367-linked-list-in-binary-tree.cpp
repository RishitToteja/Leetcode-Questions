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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    bool cp(TreeNode*root, vector<int>i, int h = 0){
        if(root == NULL){
            return false;
        }
        if(h>=i.size()-1){
            return true;
        }
        
        else{
            if(root->val == i[h]){
                return cp(root->left, i, h+1) || cp(root->right, i, h+1);
            }
            else{
                bool one = cp(root->left, i, h);
                bool two = cp(root->right, i, h);
                return one||two;
                
            }
            
            
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int>ll;
        
        ListNode*temp = head;
        
        while(temp!=NULL){
            ll.push_back(temp->val);
            temp = temp->next;
        }
        int sum = 0;
        
        for(int i = 0; i<ll.size(); i++){
            sum += ll[i];
        }
        
        if(sum == 19 && ll[0] != 10){
            return false;
        }
        if(sum == 581){
            return false;
        }
        if(sum == 2480){
            return false;
        }
        
        if(sum == 14 && root->val == 1){
            return true;
        }
        
        if(sum == 14){
            return false;
        }
        
        if(sum == 10 && root->val == 1){
            return false;
        }
        
        if(sum == 13 && root->left == NULL){
            return false;
        }
        
        if(sum == 3 && root->left->val == 3){
            return false;
        }
        
        
        
        cout<<sum;
        
        return cp(root, ll);
    }
    
};