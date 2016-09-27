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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        bool res = false;
        helper_hasPath(root, sum, 0, res);
        return res;
    }
    
    void helper_hasPath(TreeNode* root, int sum, int prefix, bool& res){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            if(prefix + root->val == sum){
                res = true;
                return;
            }
        }
        
        helper_hasPath(root->left, sum, prefix+root->val, res);
        helper_hasPath(root->right, sum, prefix+root->val, res);
    }
};