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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr = new ListNode(-1);
        ListNode* newHead = curr;
        map<int,int> mpp;
        while(head) {
            mpp[head->val]++;
            head = head->next;
        }
        for(auto i:mpp) {
            if(i.second == 1) {
                curr->next = new ListNode(i.first);
                curr = curr->next;
            }
        }
        return newHead->next;
    }
};