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
    
    int height(TreeNode* root) {
    // Write our code here
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }

        else{
            int ans_r = 1 + height(root->right);
            int ans_l = 1 + height(root->left);

            return max(ans_r, ans_l);
        }
    }
    
    int deepestLeavesSums(TreeNode* root, int actual, int sum = 0, int h = 0) {
        
        if(root->left == NULL && root->right == NULL && h == actual-1){
            sum += root->val;
            return sum;
        }
        
        else{
            int L = 0;
            int R = 0;
            if(root->left != NULL){
                L = deepestLeavesSums(root->left, actual, sum, h+1);
            }
            if(root->right != NULL){
                R = deepestLeavesSums(root->right, actual, sum, h+1);

            }
            
            return L+R;
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int actual = height(root);
        
        return deepestLeavesSums(root, actual);
        
        
    }
};