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
    unordered_set<int> st;
    unordered_map<int,int> mpp;
    int height2(TreeNode* root) {
        if(root == NULL) return 0;
        int left = height2(root->left);
        int right = height2(root->right);
        if(left > right) {
            mpp[root->val] = 1;
        }
        else mpp[root->val] = 0;
        return max(left,right)+1;
    }
    void marks(TreeNode* root) {
        if(root == NULL) return;
        if(mpp[root->val] == 1) {
            marks(root->left);
        }
        else {
            marks(root->right);
        }
        st.insert(root->val);
        return;
    }
    int height(TreeNode* root,int temp) {
        if(root == NULL || root->val == temp) return 0;
        int ans = max(height(root->left,temp),height(root->right,temp));
        return ans+1;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans;
        int prev = height2(root);
        marks(root);
        for(auto i: queries) {
            if(st.count(i)) {
                ans.push_back(height(root,i)-1);
            }
            else ans.push_back(prev-1);
        }
        return ans;
    }
};