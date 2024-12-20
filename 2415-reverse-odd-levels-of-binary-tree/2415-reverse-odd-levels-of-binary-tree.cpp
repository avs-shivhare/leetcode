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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        int cnt = 0;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<TreeNode*> temp;
            for(int i = 0; i<n; i++) {
                auto x = q.front();
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                temp.push_back(x);
            }
            if(cnt&1) {
                int l = 0,r = temp.size()-1;
                while(l<r) {
                    swap(temp[l]->val,temp[r]->val);
                    l++;
                    r--;
                }
            }
            cnt++;
        }
        return root;
    }
};