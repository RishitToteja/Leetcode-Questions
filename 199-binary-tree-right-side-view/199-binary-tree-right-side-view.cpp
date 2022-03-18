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
    
    void helper(TreeNode*root, vector<int>&i , int h){
        
        if(root == NULL){
            return ;
        }
        
        else{
            if(i[h] == -101){
                i[h] = root->val;
            }
            
            helper(root->right, i, h+1);
            helper(root->left, i, h+1);

        }
    }
    
    int height(TreeNode*root){
        if(root == NULL){
            return 0;
        }
        
        else{
            int L = 1 + height(root->left);
            int R = 1 + height(root->right);
            
            return max(L, R);

        }
    }
    vector<int> rightSideView(TreeNode* root) {
        
        int h = height(root);
        
        vector<int>um;
        
       
        for(int i = 0; i<h; i++){
            um.push_back(-101);
        }
        
        helper(root, um, 0);
        
        return um;
    }
};