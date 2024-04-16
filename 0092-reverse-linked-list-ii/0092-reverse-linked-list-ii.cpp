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
    pair<ListNode*,ListNode*> reverse(ListNode* head,int cnt,int right) {
        if(head == NULL || head->next == NULL) return {head,NULL};
        ListNode* temp = new ListNode(-1);
        while(head) {
            cnt++;
            ListNode* tempNext = temp->next;
            ListNode* next = head->next;
            head->next = tempNext;
            temp->next = head;
            head = next;
            if(cnt == right+1) {
                break;
            }
        }
        return {temp->next,head};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;
        if(left == 1) {
            ListNode* temp = head;
            auto i = reverse(head,1,right);
            temp->next = i.second;
            return i.first;
        }
        int cnt =1;
        ListNode* temp = head;
        while(temp) {
            if(cnt+1 == left) {
                break;
            }
            temp = temp->next;
            cnt++;
        }
        auto i = reverse(temp->next,cnt+1,right);
        temp->next->next = i.second;
        temp->next = i.first;
        return head;
    }
};