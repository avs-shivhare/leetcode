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
    void find(TreeNode* root,vector<int> &anc,int &maxi) {
        if(root == NULL) return;
        for(int i: anc) {
            maxi = max(maxi,abs(i-root->val));
        }
        anc.push_back(root->val);
        find(root->left,anc,maxi);
        find(root->right,anc,maxi);
        anc.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxi = 0;
        vector<int> anc;
        find(root,anc,maxi);
        return maxi;
    }
};