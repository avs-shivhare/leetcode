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
    //Iterative solution
    // ListNode* reverseList(ListNode* head) {
    //     if(head == NULL || head->next == NULL) return head;
    //     ListNode* temp = NULL;
    //     while(head) {
    //         ListNode* s = head->next;
    //         ListNode* front = temp;
    //         temp = head;
    //         temp->next = front;
    //         head = s;
    //     }
    //     return temp;
    // }

    //recursive solution
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
};