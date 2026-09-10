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
    int cnt = 0;
    pair<int,int> find(TreeNode* root) {
        if(root == NULL) return {0,0};
        auto left = find(root->left);
        auto right = find(root->right);
        if((left.first+right.first+root->val)/(left.second+right.second+1) == root->val) cnt++;
        return {left.first+right.first+root->val,left.second+right.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        find(root);
        return cnt;
    }
};