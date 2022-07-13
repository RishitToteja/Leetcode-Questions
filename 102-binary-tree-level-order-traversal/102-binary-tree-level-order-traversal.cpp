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
    map<int, vector<int>>pq;
    int m = INT_MIN;
    void helper(TreeNode*root, int h){
        if(root==NULL){
            m = max(m, h);
            return ;
        }
        else{
            pq[h].push_back(root->val);
            helper(root->left, h+1);
            helper(root->right, h+1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        vector<vector<int>>arr;
        for(int i=0; i<m; i++){
            arr.push_back(pq[i]);
        }
        return arr;
    }
};