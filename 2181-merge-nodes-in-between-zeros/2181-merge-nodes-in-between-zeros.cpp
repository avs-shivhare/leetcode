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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* newHead = head;
        ListNode* temp2 = temp->next;
        ListNode* prev = NULL;
        int sum = 0;
        while(temp2) {
            if(temp2->val == 0) {
                temp->val = sum;
                sum = 0;
                prev = temp;
                temp= temp->next;
            }
            sum += temp2->val;
            temp2 = temp2->next;
        }
        prev->next = NULL;
        return newHead;
    }
};