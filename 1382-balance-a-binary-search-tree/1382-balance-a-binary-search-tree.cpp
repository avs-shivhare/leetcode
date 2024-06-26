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
    void store(TreeNode* root,vector<int> &arr) {
        if(root == NULL) return;
        store(root->left,arr);
        arr.push_back(root->val);
        store(root->right,arr);
    }
    TreeNode* build(vector<int> &arr,int left,int right) {
        if(left > right) return NULL;
        if(left == right) {
            return new TreeNode(arr[left]);
        }
        int mid = (left+right)>>1;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = build(arr,left,mid-1);
        root->right = build(arr,mid+1,right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        store(root,arr);
        return build(arr,0,arr.size()-1);
    }
};