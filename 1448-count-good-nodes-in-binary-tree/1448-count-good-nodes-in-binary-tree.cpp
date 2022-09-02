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
class Pair{
    public:
    int max;
    
};
class Solution {
public:
    void helper(TreeNode* root, int max, int&c){
        
        if(root->left == NULL && root->right == NULL){
            if(root->val >= max){
                //max = root->val;
                c++;
            }
        }
        
        else{
            if(root->val >= max){
                max = root->val;
                c++;
            }
            
            if(root->left != NULL){
                helper(root->left, max, c);
            }
            if(root->right != NULL){
                helper(root->right, max, c);
            }
            

        }
    }
    int goodNodes(TreeNode* root) {
        
        int c = 0;
        
        helper(root, root->val, c);
        return c;
    }
};