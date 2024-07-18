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
    void find(TreeNode* root,unordered_map<TreeNode*,vector<TreeNode*>> &ans,unordered_set<TreeNode*> &mark) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            mark.insert(root);
        }
        if(root->left) {
            ans[root].push_back(root->left);
            ans[root->left].push_back(root);
        }
        if(root->right) {
            ans[root].push_back(root->right);
            ans[root->right].push_back(root);
        }
        find(root->left,ans,mark);
        find(root->right,ans,mark);
        return;
    }
    void dfs(TreeNode* node,TreeNode* &start,unordered_map<TreeNode*,vector<TreeNode*>> &lefe,unordered_set<TreeNode*> &st,set<pair<TreeNode*,TreeNode*>> &ans,int &dis,int cnt) {
        if(start != node && st.count(node) && cnt <= dis) {
            ans.insert({start,node});
        }
        if(cnt > dis) return;
        for(auto i: lefe[node]) {
            dfs(i,start,lefe,st,ans,dis,cnt+1);
        }
    }
    int countPairs(TreeNode* root, int dis) {
        unordered_map<TreeNode*,vector<TreeNode*>> lefe;
        unordered_set<TreeNode*> st;
        find(root,lefe,st);
        set<pair<TreeNode*,TreeNode*>> ans;
        for(auto i: st) {
            dfs(i,i,lefe,st,ans,dis,0);
        }
        int x = 0,lex = 0;
        for(auto i: ans) {
            if(ans.count({i.second,i.first})) lex++;
            else x++;
        }
        return x+(lex/2);
    }
};