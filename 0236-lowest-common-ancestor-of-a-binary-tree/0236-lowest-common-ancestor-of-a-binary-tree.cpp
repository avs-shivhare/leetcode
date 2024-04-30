/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // bool dfs(TreeNode* root,TreeNode* p,TreeNode* q,TreeNode* &ans) {
    //     if(root == NULL) return false;
    //     if(root->val == p->val) return true;
    //     if(root->val == q->val) return true;
    //     bool left = dfs(root->left,p,q,ans);
    //     bool right = dfs(root->right,p,q,ans);
    //     if(left && right) {
    //         ans = root;
    //         return false;
    //     }
    //     return left || right;
    // } 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        if(root->val == p->val || root->val == q->val) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        if(left == NULL) return right;
        if(right == NULL) return left;
        return NULL;
    }
};