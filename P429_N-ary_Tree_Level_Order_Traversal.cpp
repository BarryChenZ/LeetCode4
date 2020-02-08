/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
private:
    int k = -1;
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        dfs(res, root, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, Node* root, int height){
        if(!root) return;
        if(height > k){
            vector<int> tmp;
            tmp.push_back(root->val);
            res.push_back(tmp);
            k = height;
        }
        else{
            res[height].push_back(root->val);
        }
        for(int i = 0; i < root->children.size(); i++){
            dfs(res, root->children[i], height + 1);
        }
        return;
    }
};
