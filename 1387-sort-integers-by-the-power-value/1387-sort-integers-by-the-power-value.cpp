class Solution {
public:
    int f(int val,unordered_map<int,int> &dp) {
        if(val == 1) return 0;
        if(dp.find(val) != dp.end()) return dp[val];
        if(val & 1) {
            return dp[val] = 1+f(3*val+1,dp);
        }
        return dp[val] = 1+f(val/2,dp);
    }
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int,int>> q;
        for(int i =lo; i<= hi; i++) {
            unordered_map<int,int> dp;
            int val = f(i,dp);
            if(q.size() < k) {
                q.push({val,i});
            }
            else {
                if(q.top().first > val) {
                    q.pop();
                    q.push({val,i});
                }
            }
        }
        return q.top().second;
    }
};