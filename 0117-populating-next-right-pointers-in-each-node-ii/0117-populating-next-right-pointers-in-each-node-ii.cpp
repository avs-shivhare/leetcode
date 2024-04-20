/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void f(Node* root,Node* temp) {
        if(root == NULL) return;
        if(temp){ 
            root->next = temp;
            if(temp->left) temp = temp->left;
            else if(temp->right) temp= temp->right;
        }
        if(root->left) f(root->left,root->right);
        if(root->right) f(root->right,temp);
    }
    Node* connect(Node* root) {
        // f(root,NULL);
        // return root;
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i =0; i<n; i++) {
                Node* temp = q.front();
                q.pop();
                if(i+1 < n) {
                    temp->next = q.front();
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};