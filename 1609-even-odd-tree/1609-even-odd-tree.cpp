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
    void helper(TreeNode*root, vector<vector<int>>&i, int h){
        if(root->left == NULL && root->right == NULL){
            i[h].push_back(root->val);            
        }
        
        else{
            i[h].push_back(root->val);
            
            if(root->left != NULL){
                helper(root->left, i, h+1);
            }
            
            
            if(root->right != NULL){
                helper(root->right, i, h+1);
            }
        }
    }
    
    int height(TreeNode*root){
        if(root == NULL){
            return 0;
        }
        
        
        else{
            int L = 1 + height(root->left);
            int R = 1 + height(root->right);
            
            return max(L, R);

        }
    }
    
    string even_odd(vector<int>a){
        string bol ="even";
        for(int i = 0; i<a.size(); i++){
            
            if(a[i] %2 != 0){
                bol = "odd";
            }
        }
        
        
        return bol;
    }
    
    string odd_even(vector<int>a){
        string bol ="odd";
        for(int i = 0; i<a.size(); i++){
            
            if(a[i] %2 == 0){
                bol = "even";
            }
        }
        
        
        return bol;
    }
    
    void print(vector<int>a){
        for(int i = 0; i<a.size(); i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
    bool inc(vector<int>a){
        
        bool bol = true;
        
        for(int i = 1; i<a.size(); i++){
            if(a[i] <= a[i-1]){
                //cout<<a[i-1]<<" "<<a[i];
                bol = false;
            }
        }
        return bol;
    }
    
    bool dec(vector<int>a){
        
        bool bol = true;
        
        for(int i = 1; i<a.size(); i++){
            if(a[i] >= a[i-1]){
                bol = false;
            }
        }
        return bol;
    }
    bool isEvenOddTree(TreeNode* root) {
        
        vector<vector<int>>a;
        int h = height(root);
        for(int i = 0; i<h; i++){
            vector<int>temp = {};
            a.push_back(temp);
        }
        
        helper(root, a, 0);
        
        
        vector<int>temp = {7, 42, 46};
        cout<<odd_even(temp);
        bool bol = true;
        for(int i = 0; i<a.size(); i++){
            print(a[i]);
            if(i%2 == 0){
                if(odd_even(a[i]) == "even"){
                    bol = false;
                }
                if(!inc(a[i])){
                    bol = false;
                }
            }
            if(i%2 != 0){
                if(even_odd(a[i]) == "odd"){
                    bol = false;
                }
                if(!dec(a[i])){
                    bol = false;
                }
            }
        }
        
        
        return bol;
    
    }
};