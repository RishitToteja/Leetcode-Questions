/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    unordered_map<int, vector<int>>mp;
    int m = INT_MIN;
    void helper(Node*root, int h){
        if(root==NULL){
            return ;
        }
        mp[h].push_back(root->val);
        m = max(m, h);
        for(int i=0; i<root->children.size(); i++){
            helper(root->children[i], h+1);
        }
        return ;
    }
    vector<vector<int>> levelOrder(Node* root) {
        helper(root, 0);
        vector<vector<int>>arr;
        
        for(int i=0; i<=m; i++){
            arr.push_back(mp[i]);
        }
        return arr;
    }
};