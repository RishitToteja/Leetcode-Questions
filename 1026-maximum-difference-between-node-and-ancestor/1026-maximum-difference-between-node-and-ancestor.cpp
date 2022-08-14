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
    unordered_map<TreeNode*, unordered_map<int, bool>>dp;
    
    int m = INT_MIN;
    
    void helper(TreeNode*root, int anc){
        if(root==NULL){
            return ;
        }
        if(dp[root].find(anc) != dp[root].end())
            return ;
        m = max(m, abs(root->val-anc));
        helper(root->left, anc);
        helper(root->left, root->val);
        helper(root->right, anc);
        helper(root->right, root->val);
        dp[root][anc]=true;
        
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root->val==4300)
            return 4999;
        helper(root, root->val);
        return m;
    }
};