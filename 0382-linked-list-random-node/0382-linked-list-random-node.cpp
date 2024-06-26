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
    int len = 0;
    ListNode* temp = NULL;
    Solution(ListNode* head) {
        temp = head;
        while(head) {
            len++;
            head = head->next;
        }
    }
    
    int getRandom() {
        int val = rand()%len;
        ListNode* f = temp;
        while(f) {
            if(val == 0) return f->val;
            f= f->next;
            val--;
        }
        //if(f) return f->val;
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */