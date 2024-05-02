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
        ListNode* temp = new ListNode(-1);
        while(head) {
            ListNode* next = head->next;
            ListNode* tempNext = temp->next;
            temp->next = head;
            head->next = tempNext;
            head = next;
        }
        return temp->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        int carry = 0;
        ListNode* temp = new ListNode(-1);
        ListNode* head = temp;
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        while(l1 && l2) {
            int val = carry + l1->val+ l2->val;
            temp->next = new ListNode(val%10);
            temp = temp->next;
            carry = val/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int val = carry +l1->val;
            temp->next = new ListNode(val%10);
            temp = temp->next;
            carry = val/10;
            l1 = l1->next;
        }
        while(l2) {
            int val= carry+l2->val;
            temp->next = new ListNode(val%10);
            temp = temp->next;
            carry = val/10;
            l2 = l2->next;
        }
        if(carry) {
            temp->next = new ListNode(carry);
        }
        return reverseLL(head->next);
    }
};