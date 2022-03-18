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
    void helper(TreeNode*parent, TreeNode*child, int&count){
        if(child == NULL){
            return ;
        }
        
    
        helper(child, child->left, count);
        helper(child, child->right, count);
            
        if(child->val > 1){
            int req = (child->val-1);
            child->val = 1;
            parent->val += req;
            count += req;
            
        }
            
        else if(child->val < 1){
            int req = 1 + abs(child->val);
            child->val = 1;
            parent->val -= req;
            count += req;
            
               
                
        }

    }
    int distributeCoins(TreeNode* root) {
        int c = 0;
        helper(root, root, c);
        
        
        return c;
        
    }
};