/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*>mp;
    bool vis[101];
    void helper(Node* node) {
        
        if(vis[node->val]){
            return ;
        }
        vis[node->val]=true;
        if(mp.find(node->val) != mp.end()){
            for(int i=0; i<node->neighbors.size(); i++){
                Node*child = node->neighbors[i];
                if(mp.find(child->val) != mp.end())
                    mp[node->val]->neighbors.push_back(mp[child->val]);
                else{
                    Node*n = new Node(child->val);
                    mp[child->val]=n;
                    mp[node->val]->neighbors.push_back(n);
                }
                helper(child);
            }
        }
        else{
            Node*n = new Node(node->val);
            mp[node->val]=n;
            vis[node->val]=false;
            helper(node);
        }
        
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return node;
        if(node->val==1 && node->neighbors.size()==0){
            Node*n = new Node(node->val, {});
            return n;
        }
        memset(vis, false, 101);
        
        helper(node);
        
        // for(auto i: mp){
        //     cout<<i.first<<" ";
        //     for(int j=0; j<i.second->neighbors.size(); j++){
        //         cout<<i.second->neighbors[j]->val<<",";
        //     }
        //     cout<<endl;
        // }
        return mp[1];
    }
};