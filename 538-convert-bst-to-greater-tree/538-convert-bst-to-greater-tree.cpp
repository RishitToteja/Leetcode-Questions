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
    int replaceWithLargerNodesSum(TreeNode *root, int sum = 0) {
    // Write your code here
    if(root == NULL){
        return sum;
    }
    
    else{
        sum = replaceWithLargerNodesSum(root->right, sum);
        sum +=root->val;
        root->val = sum;
        sum = replaceWithLargerNodesSum(root->left, sum);
        
        return sum;
    }
}
    TreeNode* convertBST(TreeNode* root) {
        replaceWithLargerNodesSum(root);
        return root;
    }
};