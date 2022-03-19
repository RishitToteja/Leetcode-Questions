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
#include <stack>
class Solution {
public:
    void zigZagOrder(TreeNode*root, vector<vector<int>>&a) {
    // Write your code here
    
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
    
        s1.push(root);
        int i = 0;
        
        while(!s1.empty() || !s2.empty()){

            while(!s1.empty()){
                TreeNode* front = s1.top();
                s1.pop();
                a[i].push_back(front->val);
                cout<<front->val<<" ";
                if(front->left != NULL)
                    s2.push(front->left);
                if(front->right != NULL)
                    s2.push(front->right);
            }
            i++;
            cout<<endl;

            while(!s2.empty()){
                TreeNode*front = s2.top();
                s2.pop();
                a[i].push_back(front->val);
                cout<<front->val<<" ";
                if(front->right != NULL)
                    s1.push(front->right);
                if(front->left != NULL)
                    s1.push(front->left);

            }
            i++;
            cout<<endl;
        }
    }
    
    int height(TreeNode*root){
        if(root == NULL){
            return 0;
        }
        else{
            int L = height(root->left);
            int R = height(root->right);
            
            return 1 + max(L,R);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        int h = height(root);
        for(int i = 0; i<h; i++){
            vector<int>temp = {};
            ans.push_back(temp);
            
        }
        zigZagOrder(root, ans);
            
        return ans;
    }
};