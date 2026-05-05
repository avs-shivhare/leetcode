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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode* temp = head;
        int len = 0;
        while(temp) {
            len++;
            temp = temp->next;
        }
        temp = head;
        k %= len;
        while(k-- && temp) {
            temp = temp->next;
        }
        if(head == temp) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(temp && temp->next) {
            temp = temp->next;
            prev = curr;
            curr = curr->next;
        }
        temp->next = head;
        prev->next = NULL;
        return curr;
    }
};