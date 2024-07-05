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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* start = NULL;
        ListNode* end = NULL;
        ListNode* prev = NULL;
        ListNode* forward = head->next->next;
        ListNode* current = head->next;
        ListNode* backward = head;
        int mini = 1e9;
        int startCnt = 0;
        int currCnt = 0;
        int prevcnt = 0;
        while(forward) {
            if(current->val > forward->val && current->val > backward->val) {
                if(prev) {
                    mini = min(mini,currCnt-prevcnt);
                }
                if(start == NULL) {
                    start = current;
                    startCnt = currCnt;
                }
                prev = current;
                prevcnt = currCnt;
            }
            if(current->val < forward->val && current->val < backward->val) {
                if(prev) {
                    mini = min(mini,currCnt-prevcnt);
                }
                if(start == NULL) {
                    start = current;
                    startCnt = currCnt;
                }
                prev = current;
                prevcnt = currCnt;
            }
            forward = forward->next;
            current = current->next;
            backward = backward->next;
            currCnt++;
        }
        if(mini == 1e9) return {-1,-1};
        return {mini,prevcnt-startCnt};
    }
};