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
    int c = 0;
    
    pair<int, int>helper(TreeNode*root){
        if(root==NULL){
            return {0, 0};
        }
        pair<int, int>l = helper(root->left);
        pair<int, int>r = helper(root->right);
        int s = root->val + l.first + r.first;
        int n = 1 + l.second + r.second;
        if(s/n==root->val){
            c++;
        }
        return {s, n};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return c;
    }
};