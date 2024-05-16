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
    void f(vector<int> &ans,TreeNode* root1,TreeNode* root2) {
        if(!root1 && !root2) return;
        if(!root1) {
            f(ans,root1,root2->left);
            f(ans,root1,root2->right);
            ans.push_back(root2->val);
            return;
        }
        if(!root2) {
            f(ans,root1->left,root2);
            f(ans,root1->right,root2);
            ans.push_back(root1->val);
            return;
        }
        f(ans,root1->left,root2->left);
        if(root1 && root2) {
            ans.push_back(root1->val);
            ans.push_back(root2->val);
        }
        f(ans,root1->right,root2->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        f(ans,root1,root2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};