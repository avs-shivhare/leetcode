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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int n = q.size();
            if(level & 1) {
                int prev = 1e9;
                for(int i =0; i<n; i++) {
                    TreeNode* temp = q.front();
                    q.pop();
                    if(temp->val & 1) return false;
                    if(prev <= temp->val) return false;
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                    prev = temp->val;
                }
            }
            else {
                int prev = 0;
                for(int i =0; i<n; i++) {
                    TreeNode* temp = q.front();
                    q.pop();
                    if((temp->val & 1) == 0) return false;
                    if(prev >= temp->val) return false;
                    if(temp->left)  q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                    prev = temp->val;
                }
            }
            level++;
        }
        return true;
    }
};