/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        Trace(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        int i = 0, n = data.size();
        TreeNode* res = new TreeNode(INT_MAX);
        int j = i;
        while(i < n){
            int j = i;
            while(data[j] != ',') j++;
            j--;
            string tmp = data.substr(i, j - i + 1);
            int value = stoi(tmp);
            //cout << value << endl;
            constructBST(res, value, nullptr, 0);
            i = j + 2;
        }
        return res;
    }
    
    void Trace(TreeNode* root, string &res){
        if(!root) return;
        string tmp = to_string(root->val);
        res += tmp + ',';
        Trace(root->left , res);
        Trace(root->right, res);
    }
    
    void constructBST(TreeNode* &cur, int value, TreeNode* pre, int i){
        if(!cur || cur->val == INT_MAX){
            TreeNode* tmp = new TreeNode(value);
            if(pre == nullptr){
                cur = tmp;    
            }
            else if(pre != nullptr && i == 1)
                pre->right = tmp;    
            else if(pre != nullptr && i == 2)
                pre->left  = tmp;
            return;
        }
        if(value > cur->val)
            constructBST(cur->right, value, cur, 1);
        else if(value < cur->val)
            constructBST(cur->left , value, cur, 2);
        return;
    }
};
