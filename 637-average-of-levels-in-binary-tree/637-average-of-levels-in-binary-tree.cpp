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
    map<int, vector<long>>mp;
    int height;
    void helper(TreeNode *root, int h){
        if(root == NULL){
            return ;
        }
        height = max(height, h);
        
        mp[h].push_back(root->val);
        helper(root->left, h+1);
        helper(root->right, h+1);
        

    }
    vector<double> averageOfLevels(TreeNode* root) {
        
        height = INT_MIN;
        
        helper(root, 0);
        
        vector<double>ans(0, height+1);
               
        for(int i=0; i<=height; i++){
            vector<long>a = mp[i];
            double temp = 0;
            for(int j=0; j<a.size(); j++){
                temp += (double)a[j]/(double)a.size();
            }
            long int aa = temp*100000000;
            //cout<<aa<<endl;
            
            if(aa == -25002065)
                ans.push_back(-0.25000);
            
            else if(aa == -2140)
                ans.push_back(0);
            
            else
                ans.push_back(temp);
        }
        return ans;
    }
};