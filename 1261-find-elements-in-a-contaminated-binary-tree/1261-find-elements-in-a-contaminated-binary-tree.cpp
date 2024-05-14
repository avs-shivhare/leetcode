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
class FindElements {
public:
    //TreeNode* root = NULL;
    unordered_set<int> st;
    void recover(TreeNode* root,int val) {
        if(root == NULL) return;
        //cout<<val<<endl;
        root->val = val;
        st.insert(val);
        if(root->left) recover(root->left,val*2+1);
        if(root->right) recover(root->right,val*2+2);
    }
    FindElements(TreeNode* head) {
        recover(head,0);
        //root = head;
    }
    
    bool find(int target) {
        //for(auto i: st) cout<<i<<endl;
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */