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
    int sumEvenGrandparent(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int sum = 0;
        while(!q.empty()) {
            int n = q.size();
            for(int i =0; i<n; i++) {
                TreeNode* temp = q.front().first;
                int val = q.front().second;
                q.pop();
                if(val == 1) {
                    if(temp->left) sum += temp->left->val;
                    if(temp->right) sum += temp->right->val;
                }
                if((temp->val & 1) == 0) {
                    val = 1;
                }
                else val--;
                if(temp->left) q.push({temp->left,val});
                if(temp->right) q.push({temp->right,val});
            }
        }
        return sum;
    }
};