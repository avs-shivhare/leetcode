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
    int f(TreeNode* root,bool flag) {
        if(root->left == NULL && root->right == NULL && flag) return root->val;
        int l = 0;
        if(root->left) l = f(root->left,true);
        int r = 0;
        if(root->right) r= f(root->right,false);
        return l+r; 
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return 0;
        return f(root,true);
    }
};