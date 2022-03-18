/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
class Solution {
public:
    

    vector<int>* getPath(TreeNode *root , int data) {
        // Write your code here
        if(root == NULL){
            return NULL;
        }
        if(root->val == data){
            vector<int>*output = new vector<int>();
            output->push_back(root->val);
            return output;
        }
        vector<int>*loutput = getPath(root->left, data);
        if(loutput != NULL){
            loutput->push_back(root->val);
            return loutput;
        }
        vector<int>*routput = getPath(root->right, data);
        if(routput != NULL){
            routput->push_back(root->val);
            return routput;
        }
        else{
            return NULL;
        }


    }
    bool isNodePresent(TreeNode *root, int x) {
        // Write your code here
        if(root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL){
            if(root->val == x){
                return true;
            }
            else{
                return false;
            }
        }

        else{
            if(root->val == x){
                return true;
            }

            else{
                bool bol = isNodePresent(root->left, x);

                if(bol){
                    return true;
                }
                else{
                    bol = isNodePresent(root->right, x);
                    return bol;
                }
            }

        }
    }
    int getLCA(TreeNode* root , int a, int b) {
        // Write your code here
        if(root == NULL){
            return -1;
        }

        if(root->left == NULL && root->right == NULL){
            if(a == root->val || b == root->val ){
                return a;
            }
            else{
                return -1;
            }
        }

        if(!isNodePresent(root, a) && isNodePresent(root, b)){
            return b;
        }

        if(!isNodePresent(root, b) && isNodePresent(root, a)){
            return a;
        }

        if(!isNodePresent(root, b) && !isNodePresent(root, a)){
            return -1;
        }
        vector<int>*temp1 = getPath(root, a);
        vector<int>*temp2 = getPath(root, b);
        int common = 0;
        

        if(temp1->size() < temp2->size()){
            for(int i = 0; i<temp1->size(); i++){
                bool bol = false;
                for(int j = 0; j<temp2->size(); j++){
                    if(temp1->at(i) == temp2->at(j)){
                        bol = true;
                        common = temp2->at(j);
                    }
                }
                if(bol){
                    break;
                }
            }
        }

        else{
            for(int i = 0; i<temp2->size(); i++){
                bool bol = false;
                for(int j = 0; j<temp1->size(); j++){
                    if(temp2->at(i) == temp1->at(j)){
                        bol = true;
                        common = temp1->at(j);
                    }
                }
                if(bol){
                    break;
                }
            }
        }

        return common;


    }
    
    TreeNode* find(TreeNode*root, int data){
        if(root == NULL){
            return NULL;
        }
        else{
            
            if(root->val == data){
                return root;
            }
            
            else{
                TreeNode*L = find(root->left, data);
                if(L != NULL){
                    return L;
                }
                return find(root->right, data);
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int ans = getLCA(root , p->val, q->val);
        return find(root, ans);
    }
};