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
    TreeNode* deleteNode(TreeNode* root, int key) {
        Trace(root, key, nullptr, 0);
        return root;
    }
    void Trace(TreeNode* &cur, int key, TreeNode* pre, int i){
        if(!cur) return;
        if(cur->val == key){
            TreeNode* replaceNode = merge(cur->left, cur->right);
            if(i == 1 && pre != nullptr) pre->left = replaceNode;
            else if(i == 2 && pre != nullptr) pre->right = replaceNode;
            else if(i == 0)
                cur = replaceNode;
        }
        else if(cur->val > key){
            Trace(cur->left , key, cur, 1);
        }
        else if(cur->val < key){
            Trace(cur->right, key, cur, 2);
        }
        return;
    }
    TreeNode* merge(TreeNode* left, TreeNode* right){
        if (left != nullptr) { 
            TreeNode *cur = left;
            while (cur && cur->right) cur = cur->right;
            cur->right = right;
            return left;
        }
        return right;    
    }
};
