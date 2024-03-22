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
            head->next = temp;
            temp = head;
            head = s;
        }
        return temp;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = reverseLL(slow);
        while(head && fast) {
            if(head->val != fast->val) return false;
            head = head->next;
            fast = fast->next;
        }
        return true;
    }
};