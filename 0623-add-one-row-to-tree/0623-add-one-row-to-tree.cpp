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
    void f(TreeNode* root,int val,int depth) {
        if(root== NULL) return;
        if(depth-1 == 0) {
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;
            root->left = new TreeNode(val,leftTemp,NULL);
            root->right = new TreeNode(val,NULL,rightTemp);
            return;
        }
        f(root->left,val,depth-1);
        f(root->right,val,depth-1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) return new TreeNode(val,root,NULL);
        f(root,val,depth-1);
        return root;
    }
};