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
    bool flag = true;
    int find(TreeNode* root) {
        if(root == NULL) return 0;
        int l = find(root->left);
        int r = find(root->right);
        int diff = abs(r-l);
        if(diff > 1) {
            flag = false;
            return 1e6;
        }
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        flag = true;
        find(root);
        return flag;
    }
};