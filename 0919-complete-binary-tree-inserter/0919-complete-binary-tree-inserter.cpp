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
class CBTInserter {
public:
    TreeNode* head = NULL;
    queue<TreeNode*> q;
    CBTInserter(TreeNode* root) {
        q.push(root);
        head = root;
    }
    
    int insert(int val) {
        while(!q.empty()) {
            int n = q.size();
            for(int i =0; i<n; i++) {
                TreeNode* temp = q.front();
                if(temp->left) q.push(temp->left);
                else {
                    temp->left = new TreeNode(val);
                    q.push(temp->left);
                    return temp->val;
                }
                if(temp->right) q.push(temp->right);
                else {
                    temp->right = new TreeNode(val);
                    q.push(temp->right);
                    return temp->val;
                }
                q.pop();
            }
        }
        return 0;
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */