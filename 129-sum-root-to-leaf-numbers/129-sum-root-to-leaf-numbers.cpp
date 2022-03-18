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
#include <string>

class Solution {
public:
    void helper(TreeNode*root, vector<string>&i, string s = ""){
        if(root->left == NULL && root->right == NULL){
            s += to_string(root->val);
            i.push_back(s);
        }
        
        else{
            
            s += to_string(root->val);
            if(root->left != NULL){
                helper(root->left, i, s);
            }
            
            if(root->right != NULL){
                helper(root->right, i, s);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        
        vector<string>ans;
        helper(root, ans);
        
        int sum = 0;
        for(string i: ans){
            cout<<i<<" ";
            sum += stoi(i);
        }
        
        return sum;
    }
};