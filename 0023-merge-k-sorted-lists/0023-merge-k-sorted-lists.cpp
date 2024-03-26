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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(int i =0;i<n; i++) {
            if(lists[i]) pq.push({lists[i]->val,lists[i]});
        }
        while(!pq.empty()) {
            auto i = pq.top();
            pq.pop();
            if(i.second->next) pq.push({i.second->next->val,i.second->next});
            temp->next =i.second;
            temp = temp->next;
        }
        return head->next;
    }
};