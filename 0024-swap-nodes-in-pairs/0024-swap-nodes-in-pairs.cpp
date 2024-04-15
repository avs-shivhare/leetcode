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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        head = head->next;
        ListNode* prev = NULL;
        while(second) {
            ListNode* temp = second->next;
            first->next= temp;
            second->next = first;
            if(prev == NULL) prev = first;
            else {
                prev->next =second;
                prev = first;
            }
            if(temp == NULL) break;
            first = temp;
            second = temp->next;
        }
        return head;
    }
};