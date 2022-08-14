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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, TreeNode*>mp;
        unordered_map<int, int>f;
        unordered_map<int, int>s;
        for(int i=0; i<d.size(); i++){
            int a = d[i][0];
            int b = d[i][1];
            int c = d[i][2];
            f[a]++;
            s[b]++;
            if(mp.find(a) != mp.end()){
                if(mp.find(b) != mp.end()){
                    if(c==1)
                        mp[a]->left=mp[b];
                    else
                        mp[a]->right=mp[b];
                }
                else{
                    TreeNode*t = new TreeNode(b);
                    if(c==1)
                        mp[a]->left=t;
                    else
                        mp[a]->right=t;
                    mp[b]=t;
                }
                
            }
            else{
                TreeNode*n = new TreeNode(a);
                mp[a]=n;
                i--;
            }
        }
        for(auto i: f){
            if(s.find(i.first)==s.end())
                return mp[i.first];
        }
        return mp[50];
    }
};