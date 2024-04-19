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
    void f(TreeNode* root,int target,vector<int> temp,vector<vector<int>> &ans) {
        if(root->left == NULL && root->right == NULL) {
            temp.push_back(root->val);
            if(target-root->val == 0) ans.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        if(root->left) f(root->left,target-root->val,temp,ans);
        if(root->right) f(root->right,target-root->val,temp,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        f(root,targetSum,{},ans);
        return ans;
    }
};