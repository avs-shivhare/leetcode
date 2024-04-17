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
    void f(TreeNode* root,string ans,set<string> &st) {
        if(root->left == NULL && root->right == NULL) {
            char t = (root->val+'a');
            ans = t+ans;
            st.insert(ans);
            return;
        }
        char t = (root->val+'a');
        ans = t+ans;
        if(root->left) f(root->left,ans,st);
        if(root->right) f(root->right,ans,st);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(root == NULL) return "";
        set<string> st;
        f(root,"",st);
        return *(st.begin());
    }
};