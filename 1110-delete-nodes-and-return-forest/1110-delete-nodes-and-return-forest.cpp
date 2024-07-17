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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        unordered_set<int> st(del.begin(),del.end());
        queue<TreeNode*> q;
        vector<TreeNode*> ans;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i =0; i<n; i++) {
                auto x = q.front();
                q.pop();
                if(st.count(x->val)) {
                    if(x->left) {
                        if(st.count(x->left->val) == 0) {
                            ans.push_back(x->left);
                        }
                        q.push(x->left);
                        x->left = NULL;
                    }
                    if(x->right) {
                        if(st.count(x->right->val)== 0) {
                            ans.push_back(x->right);
                        }
                        q.push(x->right);
                        x->right = NULL;
                    }
                }
                else {
                    if(ans.empty()) {
                        ans.push_back(x);
                    }
                    if(x->left) {
                        if(st.count(x->left->val)) {
                            q.push(x->left);
                            x->left = NULL;
                        }
                        else {
                            q.push(x->left);
                        }
                    }
                    if(x->right) {
                        if(st.count(x->right->val)) {
                            q.push(x->right);
                            x->right = NULL;
                        }
                        else {
                            q.push(x->right);
                        }
                    }
                }
            }
        }
        return ans;
    }
};