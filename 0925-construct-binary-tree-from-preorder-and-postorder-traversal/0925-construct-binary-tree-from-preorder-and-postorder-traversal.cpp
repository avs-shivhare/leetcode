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
    unordered_map<int,int> mpp;
    TreeNode* build(int l,int r,vector<int> &pre,vector<int> &post,int &cnt) {
        if(l > r || cnt >= pre.size()) return NULL;
        TreeNode* root = new TreeNode(pre[cnt++]);
        if(l == r) return root;
        int ind = mpp[pre[cnt]];
        if(ind <=r) {
            root->left = build(l,ind,pre,post,cnt);
            root->right = build(ind+1,r-1,pre,post,cnt);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = post.size();
        for(int i = 0; i<n; i++) {
            mpp[post[i]] = i;
        }
        int cnt = 0;
        return build(0,mpp[pre[0]],pre,post,cnt);
    }
};