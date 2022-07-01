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
class tree{
    public:
    int val;
    int row;
    int col;
    int h;
    tree*left;
    tree*right;
    tree(int val){
        this->val=val;
    }
};

class Solution {
public:
    
    unordered_map<int, vector<pair<int, int>>>pq;
    
    void toarr(tree*root){
        if(root == NULL){
            return ;
        }
        pq[root->col].push_back({root->val, root->h});
        toarr(root->left);
        toarr(root->right);
    }
    tree* copy(TreeNode*root, int ro, int c, int he){
        if(root == NULL)
            return NULL;
        tree *r = new tree(root->val);
        r->row = ro;
        r->col = c;
        r->h = he;
        r->left = copy(root->left, ro+1, c-1, he+1);
        r->right = copy(root->right, ro+1, c+1, he+1);
        return r;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        tree* r = copy(root, 0, 0, 0);
        toarr(r);
        vector<vector<int>>arr;
        vector<int>a;
        for(auto &i: pq){
            a.push_back(i.first);
        }
        sort(a.begin(), a.end());
        for(int i: a){
            vector<pair<int, int>>q = pq[i];
            unordered_map<int, vector<int>>m;
            for(int j=0; j<q.size(); j++){
                m[q[j].second].push_back(q[j].first);
            }
            vector<int>he;
            for(auto &k: m){
                he.push_back(k.first);
            }
            sort(he.begin(), he.end());
            vector<int>top;
            for(int l: he){
                sort(m[l].begin(), m[l].end());
                for(int t: m[l]){
                    top.push_back(t);
                }
            }
            arr.push_back(top);
        }
        return arr;
    }
};