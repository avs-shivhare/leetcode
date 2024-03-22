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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        int i =0; 
        while(i++<n) fast= fast->next;
        if(!fast) return head->next;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast= fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};