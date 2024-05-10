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
    // 1st approach using stack without reversing linkedlist 
    
    // vector<int> nextLargerNodes(ListNode* head) {
    //     vector<int> ans;
    //     stack<pair<int,int>> st;
    //     int i = 0;
    //     while(head) {
    //         while(!st.empty() && st.top().first < head->val) {
    //             ans[st.top().second] = head->val;
    //             st.pop();
    //         }
    //         st.push({head->val,i});
    //         ans.push_back(0);
    //         i++;
    //         head = head->next;
    //     }
    //     return ans;
    // }

    // 2nd approach using stack and reversing linkedlist
    // function for reversing a linkedlist and finding lenght of linkedlist 
    pair<ListNode*,int> reverse(ListNode* head) {
        if(head == NULL ) return {head,0};
        ListNode* temp = new ListNode(-1);
        int len = 0;
        while(head) {
            len++;
            ListNode* next = head->next;
            ListNode* nextTemp = temp->next;
            temp->next = head;
            temp->next->next = nextTemp;
            head = next;
        }
        return {temp->next,len};
    }
    vector<int> nextLargerNodes(ListNode* head) {
        pair<ListNode*,int> i = reverse(head);
        int len = i.second;
        head = i.first;
        vector<int> ans(len,0);
        stack<int> st;
        while(head) {
            len--;
            while(!st.empty() && st.top() <= head->val) st.pop();
            if(!st.empty()) {
                ans[len] = st.top();
            }
            st.push(head->val);
            head = head->next;
        }
        return ans;
    }
};