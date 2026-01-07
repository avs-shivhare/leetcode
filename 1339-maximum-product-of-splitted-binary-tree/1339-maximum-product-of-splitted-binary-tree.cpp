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
    long long ans = LLONG_MIN;
    int mod = 1e9+7;
    long long sum = 0;
    long long find(TreeNode* root) {
        if(root == NULL) return 0;
        return find(root->left)+find(root->right)+root->val;
    }
    long long find2(TreeNode* root) {
        if(root == NULL) return 0;
        long long l = find2(root->left);
        long long r = find2(root->right);
        ans = max({ans,(sum-l)*l,(sum-r)*r});
        return (l+r+root->val);
    }
    int maxProduct(TreeNode* root) {
        sum = find(root);
        find2(root);
        return ans%mod;
    }
};