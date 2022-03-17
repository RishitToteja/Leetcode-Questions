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
    
    void helper(TreeNode*root, vector<int>&i, int h){
        if(root->left == NULL && root->right == NULL){
             i[h] += root->val;
        }
        
        else{
            
            i[h] += root->val;
            
            if(root->left != NULL){
                helper(root->left, i, h+1);
            }
            
            if(root->right != NULL){
                helper(root->right, i, h+1);
            }
            
        }
    }
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        else{
            
            int L = 1 + height(root->left);
            int R = 1 + height(root->right);
            
            
            return max(L, R);

        }
    }
    
    int maxLevelSum(TreeNode* root) {
        
        vector<int>max;
        

        if(root->left == NULL && root->right == NULL){
            max.push_back(root->val);
            return max[0];
        }
        
    
        
        int h = height(root)-1;
        
        for(int i = 0; i<=h; i++){
            max.push_back(0);   
        }
        
        
        helper(root, max, 0);
        
        pair<int, int>p;
        p.first = max[0];
        p.second = 1;
        
        for(int i = 1; i<max.size(); i++){
            if(max[i] >p.first){
                p.first = max[i];
                p.second = i+1;
            }
        }
        
        
        return p.second;
        
    }
};