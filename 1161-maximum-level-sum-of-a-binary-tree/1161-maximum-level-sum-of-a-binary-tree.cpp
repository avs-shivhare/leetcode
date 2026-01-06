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
        int cnt = 0;
        queue<TreeNode*> q;
        int ans = 0;
        int sum2 = -1e9;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            cnt++;
            int sum = 0;
            for(int i = 0; i<n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                sum += temp->val;
            }
            if(sum2 < sum) {
                sum2 = sum;
                ans = cnt;
            }
        }
        return ans;
    }
};