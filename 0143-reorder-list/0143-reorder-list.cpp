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
    ListNode* reverseLL(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = NULL;
        while(head) {
            ListNode* s = head->next;
            ListNode* temp2 = temp;
            temp= head;
            temp->next = temp2;
            head = s;
        }
        return temp;
    }
    void reorderList(ListNode* head) {
        if(head== NULL || head->next == NULL) return;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseLL(slow);
        fast = head;
        head = new ListNode(-1);
        while(slow->next) {
            ListNode* temp = fast->next;
            fast->next = slow;
            fast = temp;
            temp = slow->next;
            slow->next = fast;
            slow = temp;
        }
        return;
    }
};