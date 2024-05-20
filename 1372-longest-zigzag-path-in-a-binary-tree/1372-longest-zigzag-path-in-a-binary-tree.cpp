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
    // int check(TreeNode* root,bool right) {
    //     if(root == NULL) return 0;
    //     if(right) {
    //         return check(root->left,false)+1;
    //     }
    //     return check(root->right,true)+1;
    // }

    
    // int findLength(TreeNode* root) {
    //     if(root == NULL) return 0;
    //     int maxi = 0;
    //     if(root) {
    //         maxi = max({maxi,check(root,true)-1,check(root,false)-1});
    //     }
    //     return maxi = max({maxi,findLength(root->left),findLength(root->right)});
    // }


    void check(TreeNode* root,bool right,int cnt,int &ans) {
        if(root == NULL) return;
        ans = max(ans,cnt);
        if(right) {
            check(root->left,false,cnt+1,ans);
            check(root->right,true,1,ans);
        }
        else {
            check(root->right,true,cnt+1,ans);
            check(root->left,false,1,ans);
        }
    }

    int longestZigZag(TreeNode* root) {
        //return findLength(root);
        int ans = 0;
        check(root,true,0,ans);
        check(root,false,0,ans);
        return ans;
    }
};