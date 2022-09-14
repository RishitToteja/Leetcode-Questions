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
    
    int ans;
    unordered_map<int, int>mp;
    void check(){
        int odd=0;
        for(auto i: mp){
            if(i.second & 1)odd++;
            if(odd>1){
                return ;
            }
        }
        ans++;
    } 
    void helper(TreeNode*root){
        if(root->left==NULL && root->right==NULL){
            mp[root->val]++;
            check();
            mp[root->val]--;
            return ;
        }
        mp[root->val]++;
        if(root->left!=NULL)
            helper(root->left);
        
        if(root->right!=NULL)
            helper(root->right);
        
        mp[root->val]--;
        return ;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }
};