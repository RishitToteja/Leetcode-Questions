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
private:
    bool check(int val, int low, int high){
        if(val>=low && val<=high){
            return false;
        }
        else{
            return true;
        }
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return NULL;
        }
        else{
            if(root->val < low){
                root = root->right;
                if(root == NULL){
                    return root;
                }
                else{
                    return trimBST(root, low, high);
                }
                
            }
            if(root->val > high){
                root = root->left;
                if(root == NULL){
                    return root;
                }
                else{
                    return trimBST(root, low, high);
                }
            }
            
            else{
                TreeNode*l = trimBST(root->left, low, high);
                TreeNode*r = trimBST(root->right, low, high);
                
                root->left = l;
                root->right = r;
                
                return root;
            }
        }
    }
};