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
    void preOrder(TreeNode* root,vector<int> &pre) {
        if(!root) return;
        preOrder(root->left,pre);
        pre.push_back(root->val);
        preOrder(root->right,pre);
        return;
    }
    TreeNode* create(vector<int> &pre,int low,int high) {
        if(low > high) return NULL;
        int ind = -1;
        int maxi = 0;
        for(int i = low; i<=high; i++) {
            if(maxi < pre[i]) {
                maxi = pre[i];
                ind = i;
            }
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = create(pre,low,ind-1);
        root->right = create(pre,ind+1,high);
        return root;
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> pre;
        preOrder(root,pre);
        pre.push_back(val);
        return create(pre,0,pre.size()-1);
    }
};