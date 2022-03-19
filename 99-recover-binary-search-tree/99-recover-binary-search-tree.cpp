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
    void to_arr(TreeNode*root, vector<int>&a){
        if(root == NULL){
            return ;
        }
        
        else{
            to_arr(root->left, a);
            a.push_back(root->val);
            to_arr(root->right, a);
            

        }
    }
    
    TreeNode* find(TreeNode*root, int data){
        if(root == NULL){
            return NULL;
        }
        
        else{
            if(root->val == data){
                return root;
            }
            
            TreeNode*l = find(root->left, data);
            if(l == NULL){
                return find(root->right, data);
            }
            else{
                return l;
            }
        }
    }
    // 3 2 1
    // 1 2 3
    void print(vector<int>a){
        for(int i = 0; i<a.size(); i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void recoverTree(TreeNode* root) {
        vector<int>arr;
        to_arr(root, arr);
        
        int a1 = INT_MIN;
        int a2 = INT_MIN;
        
        print(arr);
        
        vector<int>temp;
        for(int i: arr){
            temp.push_back(i);
        }
        
        sort(temp.begin(), temp.end());

        int j = 0;
        
        for(int i = 0; i<arr.size(); i++, j++){
            if(arr[i] != temp[j]){
                if(a1 == INT_MIN){
                    a1 = arr[i];
                }
                if(a1 != INT_MIN){
                    a2 = arr[i];
                }
            }
        }
        
        cout<<a1<<" "<<a2;
        TreeNode*one = find(root, a1);
        TreeNode*two = find(root, a2);
        
        
        two->val = a1;
        one->val = a2;
        
    }
};