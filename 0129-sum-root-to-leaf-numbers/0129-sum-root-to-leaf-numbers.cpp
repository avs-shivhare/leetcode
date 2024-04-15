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
    void f(TreeNode* root,long long sum,long long &ans) {
        if(root->left == NULL && root->right == NULL) {
            ans += sum*10+root->val;
            return;
        }
        if(root->left) f(root->left,sum*10+root->val,ans);
        if(root->right) f(root->right,sum*10+root->val,ans);
    }
    int sumNumbers(TreeNode* root) {
        long long ans =0;
        f(root,0,ans);
        return ans;
    }
};