/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL) return NULL;
        unordered_map<TreeNode*,TreeNode*> mpp;
        queue<TreeNode*> q;
        q.push(root);
        unordered_set<TreeNode*> node;
        while(!q.empty()) {
            int n = q.size();
            unordered_set<TreeNode*> temp;
            for(int i = 0; i<n; i++) {
                TreeNode* x = q.front();
                q.pop();
                temp.insert(x);
                if(x->left) {
                    q.push(x->left);
                    mpp[x->left] = x;
                }
                if(x->right) {
                    q.push(x->right);
                    mpp[x->right] = x;
                }
            }
            node = temp;
        }
        while(node.size() > 1) {
            unordered_set<TreeNode*> temp;
            for(auto i: node) {
                if(mpp.count(i)) temp.insert(mpp[i]);
            }
            node = temp;
        }
        return *node.begin();
    }
};