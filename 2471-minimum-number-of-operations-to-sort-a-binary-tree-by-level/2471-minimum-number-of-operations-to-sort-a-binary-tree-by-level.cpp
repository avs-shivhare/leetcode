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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i<n; i++) {
                auto x = q.front();
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                temp.push_back(x->val);
            }
            int cnt = 0;
            for(int i = 0; i<n; i++) {
                int idx = i;
                for(int j = i+1; j<n; j++) {
                    if(temp[idx] > temp[j]) {
                        idx = j;
                    }
                }
                if(idx != i) {
                    swap(temp[idx],temp[i]);
                    cnt++;
                }
            }
            ans += cnt;
        }
        return ans;
    }
};