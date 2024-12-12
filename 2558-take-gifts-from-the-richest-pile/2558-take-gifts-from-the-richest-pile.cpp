class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<int> q;
        for(auto i: gifts) q.push(i);
        while(!q.empty() && k) {
            auto x = q.top();
            q.pop();
            k--;
            x = sqrt(x);
            q.push(x);
        }
        while(!q.empty()) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};