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
    long long ans = 0;
    int sums(TreeNode*root){
        if(root == NULL){
            return 0;
        }
        
        else{
            return root->val + sums(root->left) + sums(root->right);
        }
    }
    int maxP(TreeNode*root, int sum){
        if(root == NULL){
            return 0;
        }
        
        else{
            long long left = maxP(root->left, sum); 
            long long right = maxP(root->right, sum);
            long long up = sum - left - right - root->val; //17
            
            long long one = up*(left+right+root->val);
            long long two = left*(up+right+root->val);
            long long three = right*(up+left+root->val);
            
            cout<<one<<" "<<two<<" "<<three<<endl;
            ans = max(ans, max(one, max(two, three)));
            
            return left+right+root->val;
        }
    }
    int maxProduct(TreeNode* root) {
        int s = sums(root);
        cout<<s<<endl;
        maxP(root, s);
        return ans%1000000007;
    }
};