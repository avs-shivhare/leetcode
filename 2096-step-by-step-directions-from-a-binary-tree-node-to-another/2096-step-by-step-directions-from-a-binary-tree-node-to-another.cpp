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
    void createAdj(TreeNode* root,unordered_map<int,vector<pair<int,char>>> &mpp) {
        if(root == NULL) return;
        if(root->left) {
            mpp[root->val].push_back({root->left->val,'L'});
            mpp[root->left->val].push_back({root->val,'U'});
        }
        if(root->right) {
            mpp[root->val].push_back({root->right->val,'R'});
            mpp[root->right->val].push_back({root->val,'U'});
        }
        createAdj(root->left,mpp);
        createAdj(root->right,mpp);
        return;
    }
    void dfs(int node,int &dest,unordered_map<int,vector<pair<int,char>>> &mpp,unordered_set<int> &st,string &ans,string &temp) {
        if(node == dest) {
            if(ans.empty() || ans.size() > temp.size()) {
                ans = temp;
                return;
            }
        }
        st.insert(node);
        for(auto i: mpp[node]) {
            if(st.count(i.first) == 0) {
                temp.push_back(i.second);
                dfs(i.first,dest,mpp,st,ans,temp);
                temp.pop_back();
            }
        }
        st.erase(node);
    }
    string getDirections(TreeNode* root, int start, int dest) {
        unordered_map<int,vector<pair<int,char>>> mpp;
        createAdj(root,mpp);
        string ans = "";
        string temp = "";
        unordered_set<int> st;
        dfs(start,dest,mpp,st,ans,temp);
        return ans;
    }
};