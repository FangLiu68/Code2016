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
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return INT_MIN;
        int res = INT_MIN;
        helper_maxPathSum(root, res);
        return res;
    }
    
    int helper_maxPathSum(TreeNode* root, int& res){
        if(root == NULL) return 0;
        int left = helper_maxPathSum(root->left, res);
        int right = helper_maxPathSum(root->right, res);
        left = left>0? left:0;
        right = right>0? right:0;
        int cur = left + right + root->val;
        res = max(cur, res);
        return max(left, right) + root->val;
    }
};