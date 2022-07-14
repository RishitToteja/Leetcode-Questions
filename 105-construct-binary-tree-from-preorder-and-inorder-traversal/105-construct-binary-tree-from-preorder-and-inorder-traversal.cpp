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
    TreeNode* buildTrees(vector<int>& preorder, vector<int>& inorder, int si, int ei, int idx) {
        if(si>ei || idx == preorder.size())
            return NULL;
        TreeNode*root = new TreeNode(preorder[idx]);
        cout<<root->val<<endl;
        cout<<si<<" "<<ei<<" "<<idx<<endl;
        int ind;
        for(int i=si; i<=ei; i++){
            if(inorder[i]==preorder[idx])
                ind = i;
        }
        TreeNode*l = buildTrees(preorder, inorder, si, ind-1, idx+1);
        
        TreeNode*r = buildTrees(preorder, inorder, ind+1, ei, idx+1+ind-si);
        root->left = l;
        root->right = r;
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return buildTrees(preorder, inorder, 0, inorder.size()-1,0);
    }
};