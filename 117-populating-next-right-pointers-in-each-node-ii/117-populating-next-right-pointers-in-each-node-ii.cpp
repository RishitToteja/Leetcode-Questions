/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<Node*>push;
    vector<vector<Node*>>arr;
    
    void printLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL) return;
 
    // Create an empty queue for level order traversal
    queue<Node *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false)
    {
        // nodeCount (queue size) indicates number
        // of nodes at current level.
        int nodeCount = q.size();
 
        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        while (nodeCount > 0)
        {
            Node *node = q.front();
            push.push_back(node);
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        arr.push_back(push);
        push = {};
    }
}
        
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        // vector<Node*>arr = levelOrder(root);
        printLevelOrder(root);
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr[i].size()-1; j++){
                arr[i][j]->next = arr[i][j+1];
            }
            arr[i][arr[i].size()-1]->next = NULL;
        }
        
        
        
        
        return arr[0][0];
        
        
    }
};