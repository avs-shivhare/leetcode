class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == 1) return 0;
        priority_queue<long long> q;
        priority_queue<long long,vector<long long>,greater<long long>> q2;
        long long mini = 0,maxi = 0;
        for(int i = 1; i<n; i++) {
            long long sum = (long long)weights[i]+(long long)weights[i-1];
            if(q.size() < k-1) {
                mini += sum;
                q.push(sum);
            }
            else if(q.top() > sum) {
                mini -= q.top();
                q.pop();
                q.push(sum);
                mini += sum;
            }
            if(q2.size() < k-1) {
                q2.push(sum);
                maxi += sum;
            }
            else if(q2.top() < sum) {
                maxi -= q2.top();
                q2.pop();
                maxi += sum;
                q2.push(sum);
            }
        }
        return maxi - mini;
    }
};