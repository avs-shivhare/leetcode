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
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right)+1; 
    }
    bool find(TreeNode* root1,TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1== NULL || root2 == NULL) return false;
        if(root1->val == root2->val) {
            bool left = false,right = false;
            left |= find(root1->left,root2->left);
            left |= find(root1->right,root2->left);
            right |= find(root1->right,root2->right);
            right |= find(root1->left,root2->right);
            return left && right;
        }
        return false;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(height(root1) != height(root2)) return false;
        return find(root1,root2);
    }
};