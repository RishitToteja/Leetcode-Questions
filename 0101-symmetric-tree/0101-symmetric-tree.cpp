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
    string one;
    string two;
    void helper1(TreeNode* root){
        if(root==NULL)return ;
        else{
            one += 'L';
            helper1(root->left);
            one += root->val+'0';
            one += 'R';
            helper1(root->right);
        }
    }
    void helper2(TreeNode* root){
        if(root==NULL)return ;
        else{
            two += 'L';
            helper2(root->right);
            two += root->val+'0';
            two += 'R';
            helper2(root->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        one = "";
        two = "";
        helper1(root);
        helper2(root);
        return one==two;
    }
};