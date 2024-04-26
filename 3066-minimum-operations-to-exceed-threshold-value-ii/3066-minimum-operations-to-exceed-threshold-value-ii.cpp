class Solution {
public:
    long long min(long long t1, long long t2) {
        if(t1 < t2) return t1;
        return t2;
    }
    long long max(long long t1, long long t2) {
        if(t1 > t2) return t1;
        return t2;
    }
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> q;
        for(long long  i: nums) {
            q.push(i);
        }
        int i = 0;
        while(true) {
            if(q.top() >= k) {
                break;
            }
            long long t1 = q.top();
            q.pop();
            long long t2 = q.top();
            q.pop();
            long long ans = min(t1,t2)*2+max(t1,t2);
            q.push(ans);
            i++;
        }
        return i;
    }
};