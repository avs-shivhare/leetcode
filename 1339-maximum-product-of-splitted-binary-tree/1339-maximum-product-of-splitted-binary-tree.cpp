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
    long long sum(TreeNode* root,vector<long long> &arr) {
        if(root == NULL) return 0;
        long long left = sum(root->left,arr);
        long long right = sum(root->right,arr);
        long long curr = left+right+root->val;
        arr.push_back(curr);
        return curr;
    }
    int maxProduct(TreeNode* root) {
        vector<long long> arr;
        long long total = sum(root,arr);
        long long maxi = -1e9;
        int mod = 1e9+7;
        for(auto i: arr) {
            maxi =max(maxi,i*(total-i));
        }
        return maxi%mod;
    }
};