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
    TreeNode* recoverFromPreorder(string s) {
        unordered_map<int,vector<TreeNode*>> mpp;
        int i = 0;
        int n = s.size();
        int c = 0;
        while(i<n) {
            string temp = "";
            while(i<n && s[i] != '-') {
                temp += s[i];
                i++;
            } 
            TreeNode* root = new TreeNode(stoi(temp));
            if(c == 0) {
                mpp[c].push_back(root);
            }
            else {
                auto x = mpp[c-1].back();
                //cout<<x->val<<endl;
                if(x->left == NULL) x->left = root;
                else if(x->right == NULL) x->right = root;
                mpp[c].push_back(root);
            }
            c = 0;
            while(i<n && s[i] == '-') {
                i++;
                c++;
            }
        }
        return mpp[0].back();
    }
};