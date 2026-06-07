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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int,TreeNode*> mpp;
        unordered_set<int> st;
        for(auto &i: des) {
            int p = i[0];
            int c = i[1];
            TreeNode* node = NULL;
            if(mpp.find(p) != mpp.end()) node = mpp[p];
            else {
                node = new TreeNode(p);
            }
            mpp[p] = node;
            if(i[2]) {
                if(mpp.find(c) != mpp.end()) node->left = mpp[c];
                else node->left = new TreeNode(c);
                mpp[c] = node->left;
                //cout<<node->val<<" left "<<node->left->val<<endl;
            }
            else {
                if(mpp.find(c) != mpp.end()) node->right = mpp[c];
                else node->right = new TreeNode(c);
                mpp[c] = node->right;
                //cout<<node->val<<" right "<<mpp[c]->right->val<<endl;
            }
            st.insert(c);
            st.insert(p);
        }
        //for(auto i: mpp) cout<<i.first<<" "<<i.second<<endl;
        for(auto &i: des) {
            st.erase(i[1]);
        }
        return mpp[*st.begin()];
    }
};