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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        ListNode* temp = head;
        if(head == NULL) return ans;
        int n = 0;
        while(temp) {
            n++;
            temp = temp->next;
        }
        int diff = max(n/k,1);
        temp = head;
        bool odd = false;
        if(n > k && n%k != 0) {
            odd = true;
        }
        int cnt = 0;
        int i = 0;
        ListNode* prev = NULL;
        while(temp && k) {
            if(cnt == 0) {
                ans[i] = temp;
            }
            else if(odd) {
                if(cnt == diff+1) {
                    k--;
                    n -= cnt;
                    prev->next = NULL;
                    i++;
                    cnt = 0;
                    if(i < ans.size()) ans[i] = temp;
                    odd = false;
                    if(n > k && n%k != 0) {
                        odd = true;
                    }
                }
            }
            else if(cnt == diff) {
                prev->next = NULL;
                k--;
                n -= cnt;
                i++;
                cnt = 0;
                if(i < ans.size()) ans[i] = temp;
            }
            cnt++;
            prev = temp;
            temp = temp->next;
        }
        return ans;
    }
};