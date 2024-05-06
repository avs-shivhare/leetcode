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
    // 1st approach using while loop first reverse the give linkedlist and remove node according to give condition than again reverse node and return it

    // reverse function that reverse give linkedlist in O(n) time complexity and O(1) space complexity 
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = new ListNode(-1);
        while(head) {
            ListNode* next = head->next;
            ListNode* tempNext = temp->next;
            temp->next = head;
            temp->next->next = tempNext;
            head = next;
        }
        return temp->next;
    }
    ListNode* removeNodes(ListNode* head) {
        // check edge case
        if(head == NULL || head->next == NULL) return head;

        //call reverse function and store in head
        head = reverse(head);
        ListNode* temp = head;
        ListNode* newHead = temp;
        head = head->next;
        // in while loop if temp values is less than equal to head value than store head 
        // in temp next
        while(head) {
            if(temp->val <= head->val) {
                temp->next = head;
                temp = temp->next;
            }
            head = head->next;
        }
        // assign last node next null
        temp->next = NULL;
        //reverse linked list and return
        return reverse(newHead);
    }

    // 2nd approach using recursion, call recursive function until head next is not null
    // if head next is null than return head, and store in temp
    // compare temp value and head value if head value is greater than and equal to temp
    // value than set head next is temp and return head
    // else return temp
    // ListNode* removeNodes(ListNode* head) {
    //     if(head->next == NULL) return head;
    //     ListNode* temp = removeNodes(head->next);
    //     if(head->val >= temp->val) {
    //         head->next = temp;
    //         return head;
    //     }
    //     return temp;
    // }
};