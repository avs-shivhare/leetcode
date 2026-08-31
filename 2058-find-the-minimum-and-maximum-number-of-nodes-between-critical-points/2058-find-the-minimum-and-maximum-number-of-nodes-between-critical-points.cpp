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
        int len = 1;
        int first = -1,last = -1;
        int mini = 1e9,maxi = -1;
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        ListNode* prev = head;
        while(fast) {
            if(prev->val < slow->val && slow->val > fast->val) {
                if(first == -1) {
                    first = len;
                }
                else {
                    mini = min(mini,len-last);
                    maxi = max(maxi,len-first);
                }
                last = len;
            }
            else if(prev->val > slow->val && slow->val < fast->val) {
                if(first == -1) {
                    first = len;
                }
                else {
                    mini = min(mini,len-last);
                    maxi = max(maxi,len-first);
                }
                last = len;
            }
            fast = fast->next;
            slow = slow->next;
            prev = prev->next;
            len++;
        }
        vector<int> ans(2,-1);
        if(maxi > 0) ans[1] = maxi;
        if(mini < 1e9) ans[0] = mini;
        return ans;
    }
};