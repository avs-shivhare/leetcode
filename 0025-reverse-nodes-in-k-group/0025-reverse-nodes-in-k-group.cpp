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
    ListNode* reverseLL(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = NULL;
        while(head) {
            ListNode* s = temp;
            ListNode* nextNode= head->next;
            temp = head;
            temp->next = s;
            head = nextNode;
        }
        return temp;
    }
    ListNode* findK(ListNode* head,int k) {
        while(head && k>1) {
            head = head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp) {
            ListNode* kth = findK(temp,k);
            if(kth == NULL) {
                break;
            }
            ListNode* nextNode = kth->next;
            kth->next = NULL;
            ListNode* revHead = reverseLL(temp);
            if(temp == head) {
                head= revHead;
            }
            if(prev) prev->next = revHead;
            prev = temp;
            temp->next = nextNode;
            temp = nextNode;
        }
        return head;
    }
};