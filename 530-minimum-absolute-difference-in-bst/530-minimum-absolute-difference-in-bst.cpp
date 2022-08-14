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
    void helper(TreeNode*root, vector<int>&a){
        if(root==NULL)
            return ;
        helper(root->left,a);
        a.push_back(root->val);
        helper(root->right, a);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>arr;
        helper(root, arr);
        
        int m = INT_MAX;
        for(int i=0; i<arr.size()-1; i++){
            m = min(m, arr[i+1]-arr[i]);
        }
        
        return m;
    }
};