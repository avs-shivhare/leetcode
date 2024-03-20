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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = list1;
        ListNode* end = list1;
        //ListNode* start2 = list2;
        ListNode* end2 =list2;
        int i =0;
        while(start->next && i < a-1) {
            start= start->next;
            end = end->next;
            i++;
        }
        while(end->next && i<=b) {
            i++;
            end = end->next;
        }
        while(end2->next) {
            end2= end2->next;
        }
        start->next = list2;
        end2->next = end;
        return list1;
    }
};