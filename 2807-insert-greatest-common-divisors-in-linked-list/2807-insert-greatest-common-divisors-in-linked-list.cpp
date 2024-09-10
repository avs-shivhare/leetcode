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
    int hcf(int a,int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a > b) {
            return hcf(a%b,b);
        }
        return hcf(a,b%a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr) {
            int temp = hcf(prev->val,curr->val);
            prev->next = new ListNode(temp,curr);
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};