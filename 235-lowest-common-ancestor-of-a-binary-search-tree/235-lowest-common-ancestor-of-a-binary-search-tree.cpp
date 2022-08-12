/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void helper(TreeNode*root, int v, vector<int>&arr){
        if(root==NULL){
            return ;
        }
        else{
            if(root->val == v){
                arr.push_back(root->val);
                return ;
            }
            else if(root->val< v){
                helper(root->right, v, arr);
                arr.push_back(root->val);
                return ;
            }
            else{
                helper(root->left, v, arr);
                arr.push_back(root->val);
                return ;
            }
        }
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>a;
        helper(root, p->val, a);
        
        vector<int>b;
        helper(root, q->val, b);
        
        unordered_map<int, int>mp;
        for(int i=0; i<a.size(); i++){
            mp[a[i]]++;
        }
        for(int i=0; i<b.size(); i++){
            if(mp.find(b[i]) != mp.end()){
                TreeNode*n = new TreeNode(b[i]);
                return n;
            }
        }
        
        return nullptr;
        
        
    }
};