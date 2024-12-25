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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int maxi = INT_MIN;
            for(int i = 0; i<n; i++) {
                auto x = q.front();
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                maxi = max(maxi,x->val);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};