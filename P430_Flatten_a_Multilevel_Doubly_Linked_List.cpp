/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
private:
    vector<Node*> temp;
public:
    Node* flatten(Node* head) {
        Node* res = head;
        dfs(head);
        return res;
    }
    void dfs(Node* head){
        if(!head) return;
        if(!head->next && !head->child){
            if(!temp.empty()){
                head->next = temp.back();
                head->next->prev = head;
                temp.pop_back();
                dfs(head->next);
            }
            return;
        }
        
        if(!head->child)
            dfs(head->next);
        
        else if(head->child){
            if(head->next) temp.push_back(head->next);
            head->next = head->child;
            head->next->prev = head;
            head->child = NULL;
            dfs(head->next);
        }
        return;
    }
};
