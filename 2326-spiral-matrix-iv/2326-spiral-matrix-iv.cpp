/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int srow = 0,erow = m-1;
        int scol = 0,ecol = n-1;
        while(head) {
            for(int i = scol; i<=ecol; i++) {
                if(head == NULL) return ans;
                ans[srow][i] = head->val;
                head = head->next;
            }
            srow++;
            if(srow > erow) break;
            for(int i = srow; i<=erow; i++) {
                if(head == NULL) return ans;
                ans[i][ecol] = head->val;
                head = head->next;
            }
            ecol--;
            if(scol > ecol) break;
            for(int i = ecol; i>=scol; i--) {
                if(head == NULL) return ans;
                ans[erow][i]= head->val;
                head = head->next;
            }
            erow--;
            for(int i = erow; i>=srow; i--) {
                if(head == NULL) return ans;
                ans[i][scol]= head->val;
                head = head->next;
            }
            scol++;
        }
        return ans;
    }
};