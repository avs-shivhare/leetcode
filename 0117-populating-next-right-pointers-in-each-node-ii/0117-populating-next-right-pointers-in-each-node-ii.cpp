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
    //optimal solution
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node* head = root;
        while(head) {
            Node* temp = new Node(-1);
            Node* tempHead = temp;
            while(head) {
                if(head->left) {
                    temp->next = head->left;
                    temp = temp->next;
                }
                if(head->right) {
                    temp->next = head->right;
                    temp = temp->next;
                }
                head = head->next;
            }
            head = tempHead->next;
        }
        return root;
    }

    //brute force solution using bsf
    // Node* connect(Node* root) {
    //     if(root == NULL) return root;
    //     queue<Node*> q;
    //     q.push(root);
    //     while(!q.empty()) {
    //         int n = q.size();
    //         for(int i =0; i<n; i++) {
    //             Node* temp = q.front();
    //             q.pop();
    //             if(i+1 < n) {
    //                 temp->next = q.front();
    //             }
    //             if(temp->left) q.push(temp->left);
    //             if(temp->right) q.push(temp->right);
    //         }
    //     }
    //     return root;
    // }
};