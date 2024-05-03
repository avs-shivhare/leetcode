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
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int p = pow(2,h);
        vector<vector<string>> ans(h,vector<string>(p-1,""));
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,(p-2)/2}});
        while(!q.empty()) {
            int n = q.size();
            for(int i =0; i<n; i++) {
                TreeNode* temp = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                q.pop();
                int colH = pow(2,h-row-2);
                if(temp->left) q.push({temp->left,{row+1,col-colH}});
                if(temp->right) q.push({temp->right,{row+1,col+colH}});
                ans[row][col] = to_string(temp->val);
            }
        }
        return ans;
    }
};