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
    TreeNode* f(vector<int> &nums,int left,int right) {
        if(left > right) return NULL;
        int maxi = 0;
        int ind = -1;
        for(int i = left; i<=right; i++) {
            if(nums[i] >= maxi) {
                maxi = nums[i];
                ind = i;
            }
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = f(nums,left,ind-1);
        root->right = f(nums,ind+1,right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return f(nums,0,n-1);
    }
};