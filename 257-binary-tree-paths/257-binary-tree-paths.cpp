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
    void helper(vector<string>&a, TreeNode*root, string s){
        if(root->left == NULL && root->right == NULL){
            s += to_string(root->val);
            a.push_back(s);
        }
        
        else{
            s += to_string(root->val);
            s += "->";
            if(root->left != NULL)
                helper(a, root->left, s);
            if(root->right != NULL)
                helper(a, root->right, s);

        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>s;
        string temp = "";
        helper(s, root, temp);
        
        return s;
    }
};