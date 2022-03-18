/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* toBST(vector<int>s, int si, int ei){
        
        if(si>ei){
            return NULL;
        }
        
        else{
            
            int mid = (si+ei)/2;
            
            TreeNode*root = new TreeNode(s[mid]);
            
            root->left = toBST(s, si, mid-1);
            root->right = toBST(s, mid+1, ei);
            
            return root;

        }
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>list;
        
        ListNode*temp = head;
        
        while(temp != NULL){
            list.push_back(temp->val);
            temp = temp->next;
        }
        
        
        return toBST(list, 0, list.size()-1);
        
    }
};