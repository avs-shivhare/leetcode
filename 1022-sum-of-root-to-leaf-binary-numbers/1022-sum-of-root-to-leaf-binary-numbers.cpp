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
    long long ans = 0;
    void find(TreeNode* root,long long val) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            val = (val<<1)|root->val;
            ans += val;
            return;
        }
        find(root->left,(val<<1)|root->val);
        find(root->right,(val<<1)|root->val);
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        find(root,0);
        return ans;
    }
};