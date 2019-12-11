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
    int res = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
    void dfs(TreeNode* root, int direction){
        if(!root) return;
        if(root->left == NULL && root->right == NULL && direction == 1) res += root->val;
        dfs(root->left, 1);
        dfs(root->right, 2);
        return;
    }
};
