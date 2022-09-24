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
    vector<vector<int>>arr;
    void helper(TreeNode* root, int tar, vector<int>path, int curr){
        if(root->left==NULL && root->right == NULL){
            if(curr+root->val==tar){
                path.push_back(root->val);
                arr.push_back(path);
            }
            return ;
        }
        else{
            path.push_back(root->val);
            if(root->left!=NULL)
                helper(root->left, tar, path, curr+root->val);
            if(root->right!=NULL)
            helper(root->right, tar, path, curr+root->val);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return {};
        }
        vector<int>f;
        helper(root, targetSum, f, 0);
        return arr;
    }
};