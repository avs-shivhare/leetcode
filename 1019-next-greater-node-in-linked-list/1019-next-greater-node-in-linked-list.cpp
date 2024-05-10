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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int,int>> st;
        int i = 0;
        while(head) {
            while(!st.empty() && st.top().first < head->val) {
                ans[st.top().second] = head->val;
                st.pop();
            }
            st.push({head->val,i});
            ans.push_back(0);
            i++;
            head = head->next;
        }
        return ans;
    }
};