class Solution {
public:
    int kthFactor(int n, int k) {
        priority_queue<int> q;
        for(int i =1; i*i<=n; i++) {
            if(n%i == 0) {
                if(i == n/i) {
                    if(q.size() < k) {
                        q.push(i);
                    }
                    else {
                        if(q.top() > i) {
                            q.pop();
                            q.push(i);
                        }
                    }
                    continue;
                }
                if(q.size() < k) {
                    q.push(i);
                }
                else {
                    if(q.top() > i) {
                        q.pop();
                        q.push(i);
                    }
                }
                if(q.size() < k) {
                    q.push(n/i);
                }
                else {
                    if(q.top()> n/i) {
                        q.pop();
                        q.push(n/i);
                    }
                }
            }
        }
        if(q.size() == k) return q.top();
        return -1;
    }
};