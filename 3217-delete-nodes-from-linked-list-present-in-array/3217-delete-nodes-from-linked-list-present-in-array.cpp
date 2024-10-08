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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto i: nums) {
            st.insert(i);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* newHead = dummy;
        while(head) {
            if(st.count(head->val) == 0) {
                dummy->next = head;
                dummy = dummy->next;
            }
            head = head->next;
        }
        dummy->next = NULL;
        return newHead->next;
    }
};