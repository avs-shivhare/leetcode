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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mpp;
        int sum =0;
        ListNode* dummay = new ListNode(-1);
        dummay->next = head;
        mpp[0] = dummay;
        while(head) {
            sum += head->val;
            if(mpp.find(sum) != mpp.end()) {
                ListNode* start = mpp[sum];
                ListNode* temp = start;
                int psum = sum;
                while(temp != head) {
                    temp= temp->next;;
                    psum += temp->val;
                    if(temp != head) mpp.erase(psum);
                }
                start->next = head->next;
            }
            else {
                mpp[sum] = head;
            }
            head = head->next;
        }
        return dummay->next;
    }
};