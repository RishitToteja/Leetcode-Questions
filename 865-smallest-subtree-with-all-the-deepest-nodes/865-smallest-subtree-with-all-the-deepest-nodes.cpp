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

class lca{
    public:
    int depth;
    TreeNode*lca;
};

class Solution {
public:
    lca lcaDeepestLeavess(TreeNode* root) {
        
        if(root == NULL){
            lca a;
            a.depth = 0;
            a.lca = NULL;
            return a;
        }
        
        else{
            lca L = lcaDeepestLeavess(root->left);
            lca R = lcaDeepestLeavess(root->right);
            
            if(L.depth == R.depth){
                lca a;
                a.depth = R.depth+1;
                a.lca = root;
                
                return a;
            }
            
            if(L.depth > R.depth){
                lca a;
                a.depth = L.depth+1;
                a.lca = L.lca;
                a.depth = L.depth + 1;
                
                return a;
            }
            
            else{
                lca a;
                a.depth = R.depth+1;
                a.lca = R.lca;
                a.depth = R.depth + 1;
                
                return a;
            }
            
            
            
            
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        lca a = lcaDeepestLeavess(root);
        
        return a.lca;
        
    }
};