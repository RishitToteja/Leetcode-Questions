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
    void helper(TreeNode*root, vector<int>&in){
        if(root==NULL){
            return ;
        }
        helper(root->left, in);
        in.push_back(root->val);
        helper(root->right, in);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>in;
        helper(root, in);
        unordered_map<int, int>mp;
        for(int i=0; i<in.size(); i++){
            mp[in[i]]=i;
        }
        for(int i=0; i<in.size(); i++){
            int t = k-in[i];
            if(mp.find(t) != mp.end()){
                if(i!=mp[t])
                    return true;
            }
                
        }
        return false;
    }
};