/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()){
            TreeNode* cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            if(cur->right){
                stk.push(cur->right);
            }
            if(cur->left){
                stk.push(cur->left);
            }
        }
        
        return res;
    }
};