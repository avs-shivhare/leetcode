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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level = -1;
        int l = 0;
        int sum = 0;
        q.push(root);
        while(!q.empty()) {
            int temp = 0;
            l++;
            int n = q.size();
            for(int i =0; i<n; i++) {
                TreeNode* t = q.front();
                q.pop();
                temp += t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(level == -1 || temp > sum) {
                level = l;
                sum = temp;
            }
        }
        return level;
    }
};