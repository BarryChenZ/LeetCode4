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
private:
    int count = 0, max = 0, prenum = INT_MIN;
public:
    vector<int> ans;
    vector<int> findMode(TreeNode* root) {
        inorderTraversal(root);
        return ans;
    }
    void inorderTraversal(TreeNode* root){
        if(!root) return;
        inorderTraversal(root->left);
        if(root->val == prenum) count++;
        else count = 1;
        if(count > max){
            ans.clear();
            ans.push_back(root->val);
            max = count;
        }
        else if(count == max) ans.push_back(root->val);
        prenum = root->val;
        inorderTraversal(root->right);
        return;
    }
};
