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
    int find(unordered_set<int> &node,unordered_map<int,pair<int,int>> &mpp) {
        for(auto i: mpp) {
            if(node.count(i.first) == 0) return i.first;
        }
        return -1;
    }

    TreeNode* create(int root,unordered_map<int,pair<int,int>> &mpp) {
        if(root == 0) return NULL;
        TreeNode* temp = new TreeNode(root);
        if(mpp[root].first != 0) temp->left = create(mpp[root].first,mpp);
        if(mpp[root].second != 0) temp->right = create(mpp[root].second,mpp);
        return temp;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int,pair<int,int>> mpp;
        unordered_set<int> node;
        for(auto i: des) {
            node.insert(i[1]);
            if(i[2]) mpp[i[0]].first = i[1];
            else mpp[i[0]].second = i[1];
        }
        int root = find(node,mpp);
        return create(root,mpp);
    }
};