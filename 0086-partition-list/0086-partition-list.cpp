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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = new ListNode(-1);
        ListNode* newHead = NULL;
        ListNode* tempHead = temp;
        ListNode* p = head;
        ListNode* prev = NULL;
        while(p) {
            if(!newHead && p->val < x) {
                newHead = p;
                prev = p;
            }
            else if(p->val >= x){ 
                temp->next = p;
                temp = temp->next;
            }
            else {
                prev->next = p;
                prev = prev->next;
            }
            p = p->next;
        }
        temp->next = NULL;
        if(newHead == NULL) return head;
        prev->next = tempHead->next;
        return newHead;
    }
};