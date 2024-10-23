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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        while(!q.empty()) {
            int n = q.size();
            int sum = 0;
            queue<pair<TreeNode*,TreeNode*>> q2;
            unordered_map<TreeNode*,int> mpp;
            for(int i =0; i<n; i++) {
                auto temp = q.front();
                q.pop();
                sum += temp.first->val;
                mpp[temp.second]+=temp.first->val;
                q2.push(temp);
                if(temp.first->left) q.push({temp.first->left,temp.first});
                if(temp.first->right) q.push({temp.first->right,temp.first});
            }
            for(int i =0; i<n; i++) {
                auto temp = q2.front();
                q2.pop();
                temp.first->val = sum-mpp[temp.second];
            }
        }
        return root;
    }
};