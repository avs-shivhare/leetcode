class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> q;
        for(int i =1; i<=n; i++) {
            q.push_back(i);
        }
        while(q.size() != 1) {
            int cnt = 1;
            while(cnt != k) {
                q.push_back(q.front());
                q.pop_front();
                cnt++;
            }
            q.pop_front();
        }
        return q.front();
    }
};