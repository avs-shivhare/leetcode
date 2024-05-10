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
    TreeNode* create(string &tra, int &ind,int level) {
        if(ind >= tra.size()) return NULL;
        int len = ind;
        while(len<tra.size() && tra[len] != '-') len++;
        int val = stoi(tra.substr(ind,len-ind+1));
        TreeNode* root = new TreeNode(val);
        ind = len;
        level++;
        int cnt  =0;
        while(len < tra.size() && tra[len] == '-') {
            len++;
            cnt++;
        }
        if(cnt == level) {
            ind = len;
            root->left = create(tra,ind,level);
        }
        len = ind;
        cnt  =0;
        while(len < tra.size() && tra[len] == '-') {
            len++;
            cnt++;
        }
        if(cnt == level) {
            ind = len;
            root->right = create(tra,ind,level);
        }
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        return create(traversal,i,0);
    }
};