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
    void helper(TreeNode* root, int val, int depth, int h){
        if(root==NULL)
            return ;
        if(h+1==depth){
            TreeNode*later_r = root->right;
            TreeNode*later_l = root->left;
            
            
            TreeNode*v1 = new TreeNode(val);
            TreeNode*v2 = new TreeNode(val);
            
            
            root->right=v1;
            v1->right=later_r;
            
            
            root->left=v2;
            v2->left=later_l;

        }
        
        else{
            helper(root->left,val, depth, h+1);
            helper(root->right,val, depth, h+1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*v1 = new TreeNode(val);
            v1->left=root;
            root=v1;
            return v1;
        }
        helper(root, val, depth, 1);
        return root;
    }
};