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
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    bool isCompleteTree(TreeNode* root) {
        int h = height(root);
        queue<TreeNode*> q;
        int level = 0;
        //cout<<h<<endl;
        q.push(root);
        bool flag = false;
        while(!q.empty()) {
            int n = q.size();
            level++;
            for(int i = 0; i<n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                bool left = false,right = false;
                if(temp->left) {
                    left = true;
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                    right = true;
                }
                if(level >= h-1) {
                    if(flag && (left || right)) return false;
                    if(right && !left) return false;
                    else if((left && !right) || (!left && !right)) flag = true;
                }
                else if(!(left && right)) return false;
            }
            //cout<<level<<endl;
        }
        return true;
    }
};