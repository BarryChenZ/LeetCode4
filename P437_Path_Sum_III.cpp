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
    int k = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        vector<int> value;
        treeTraval(root, sum, value);
        return k;
    }
    void treeTraval(TreeNode* root, int sum, vector<int> value){
        if(!root) return;
        for(int i = 0; i < value.size(); i++){
            value[i] += root->val;
        }
        value.push_back(root->val);
        for(int i = 0; i < value.size(); i++){
            
            if(value[i] == sum){
                //cout << root->val << endl;
                k++;
            }
        }
        
        treeTraval(root->left , sum, value);
        treeTraval(root->right, sum, value);
    }
};
