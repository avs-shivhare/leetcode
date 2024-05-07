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

    // 1st approach using recursion 
    // first tarverse utill node is not null if node is null return 0 and store in carry 
    // calculate double of value by multiply by 2 
    // store value in node value if any carry present return carry
    int multi(ListNode* head) {
        if(head == NULL) return 0;
        int carry = multi(head->next);
        int val = (head->val*2) + carry;
        head->val = val%10;
        return val/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int val = multi(head);
        if(val) {
            head = new ListNode(val,head);
        }
        return head;
    }


    //approach 2nd using reverse function for reverse linkedlist, after reversing travers
    // in linkedlist and double value in every node value if any carry present store in 
    // carry variable 
    // at the end if carry is not equal to zero one new new node that contain carray
    // reverse this list and return
    // ListNode* reverse(ListNode* head) {
    //     if(head == NULL || head->next == NULL) return head;
    //     ListNode* temp = new ListNode(-1);
    //     while(head) {
    //         ListNode* next = head->next;
    //         ListNode* tempNext = temp->next;
    //         temp->next = head;
    //         temp->next->next = tempNext;
    //         head = next;
    //     }
    //     return temp->next;
    // }
    // ListNode* doubleIt(ListNode* head) {
    //     if(head == NULL) return head;
    //     head = reverse(head);
    //     ListNode* temp = head;
    //     ListNode* prev = NULL;
    //     int carry = 0;
    //     while(temp) {
    //         int val = temp->val*2+carry;
    //         temp->val = val%10;
    //         carry = val/10;
    //         prev = temp;
    //         temp = temp->next;
    //     }
    //     if(carry) {
    //         prev->next = new ListNode(carry);
    //     }
    //     return reverse(head);
    // }
};