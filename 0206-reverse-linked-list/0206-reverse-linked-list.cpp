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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = new ListNode(-1);
        temp->next = NULL;
        ListNode* ans = temp;
        while(head) {
            ListNode* s= head->next;
            ListNode* s1 = temp->next;
            temp->next = head;
            temp->next->next = s1;
            head = s;
        } 
        return ans->next;
    }
};