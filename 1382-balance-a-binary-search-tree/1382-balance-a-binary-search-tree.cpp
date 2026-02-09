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
    vector<int> arr;
    void preOrder(TreeNode* root) {
        if(root == NULL) return;
        preOrder(root->left);
        arr.push_back(root->val);
        preOrder(root->right);
    }
    TreeNode* build(int l,int r) {
        if(l > r) return NULL;
        if(l == r) return new TreeNode(arr[l]);
        int mid = (l+r)>>1;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = build(l,mid-1);
        root->right = build(mid+1,r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        preOrder(root);
        return build(0,arr.size()-1);
    }
};