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
class BSTIterator {
public:
    vector<int>ans;
    int i;
    void helper(TreeNode* root){
        if(root == NULL){
            return ;
        }
        
        else{
            helper(root->left);
            ans.push_back(root->val);
            helper(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        i = 0;
        helper(root);
    }
    
    int next() {
        return ans[i++];
    }
    
    bool hasNext() {
        
        return (i<ans.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */