/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    //using dfs
    void dfs(Node* head,Node* head2,unordered_map<int,Node*> &mpp,vector<bool> &vis) {
        vis[head->val] = true;
        for(int i =0; i<head->neighbors.size(); i++) {
            int val = head->neighbors[i]->val;
            if(mpp.find(val) != mpp.end()) {
                head2->neighbors.push_back(mpp[val]);
            }
            else {
                Node* x = new Node(val);
                head2->neighbors.push_back(x);
                mpp[val] = x;
            }
            if(!vis[head->neighbors[i]->val]) {
                dfs(head->neighbors[i],head2->neighbors[i],mpp,vis);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* head = new Node(node->val);
        vector<bool> vis(101,false);
        unordered_map<int,Node*> mpp;
        mpp[node->val] = head;
        vis[head->val] = true;
        dfs(node,head,mpp,vis);
        return head;
    }
};