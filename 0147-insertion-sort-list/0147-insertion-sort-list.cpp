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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        while(temp) {
            ListNode* temp2 = temp->next;
            ListNode* minNode = temp;
            int val = temp->val;
            while(temp2) {
                if(temp2->val < val) {
                    val =temp2->val;
                    minNode = temp2;
                }
                temp2 = temp2->next;
            }
            val = temp->val;
            temp->val = minNode->val;
            minNode->val = val;
            temp = temp->next;
        }
        return head;
    }
};