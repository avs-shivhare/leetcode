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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,TreeNode*> mpp;
        while(!q.empty()) {
            int n = q.size();
            for(int i =0;i<n; i++) {
                auto temp = q.front();
                q.pop();
                TreeNode* prev = temp.first;
                int level = temp.second.first;
                int x = temp.second.second;
                if(prev->left != NULL) {
                    q.push({prev->left,{level+1,x-1}});
                }
                if(prev->right != NULL) q.push({prev->right,{level+1,x+1}});
                mpp[level] = prev;
            }
        }
        for(auto i : mpp) {
            ans.push_back(i.second->val);
        }
        return ans;
    }
};