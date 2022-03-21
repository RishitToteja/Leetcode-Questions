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
    
    TreeNode* deleteNode(TreeNode* node, int data) {
        if (node == NULL) {
            return NULL;
        }
        if (data > node->val) {
            node->right = deleteNode(node->right, data);
            return node;
        } 
        else if (data < node->val) {
            node->left = deleteNode(node->left, data);
            return node;
        } 
        
        else {
            
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            } 
            
            else if (node->left == NULL) {
                TreeNode* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            } 
            else if (node->right == NULL) {
                TreeNode* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            
            else {
                TreeNode* minNode = node->right;

                while (minNode->left != NULL) {
                    minNode = minNode->left;
                }

                int rightMin = minNode->val;
                node->val = rightMin;
                node->right = deleteNode(node->right, rightMin);
                return node;
            }
        }
    }
};