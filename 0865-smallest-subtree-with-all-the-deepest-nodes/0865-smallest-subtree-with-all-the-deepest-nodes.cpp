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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> last;
        queue<TreeNode*> q;
        unordered_map<int,TreeNode*> mpp;
        q.push(root);
        while(!q.empty()) {
            vector<TreeNode*> temp;
            int n = q.size();
            for(int i = 0; i<n; i++) {
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t);
                if(t->left) {
                    q.push(t->left);
                    mpp[t->left->val] = t;
                }
                if(t->right) {
                    mpp[t->right->val] = t;
                    q.push(t->right);
                }
            }
            last = temp;
        }
        unordered_set<int> st;
        for(auto &i: last) {
            q.push(i);
        }
        while(q.size() > 1) {
            int n = q.size();
           // cout<<n<<endl;
            for(int i = 0; i<n; i++) {
                TreeNode* t = q.front();
                q.pop();
                //cout<<t->val<<" -> "<<mpp[t->val]->val<<endl;
                if(st.find(mpp[t->val]->val) == st.end()) {
                    q.push(mpp[t->val]);
                    //cout<<mpp[t->val]->val<<endl;
                    st.insert(mpp[t->val]->val);
                }
            }
        }
        //cout<<q.size()<<endl;
        if(q.size() > 0) return q.front();
        //cout<<"done"<<endl;
        return root;
    }
};