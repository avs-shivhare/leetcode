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
    void update(TreeNode* root,int &maxi) {
        if(root == NULL) return;
        update(root->right,maxi);
        root->val += maxi;
        maxi = root->val;
        update(root->left,maxi);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int maxi = 0;
        update(root,maxi);
        return root;
    }
};