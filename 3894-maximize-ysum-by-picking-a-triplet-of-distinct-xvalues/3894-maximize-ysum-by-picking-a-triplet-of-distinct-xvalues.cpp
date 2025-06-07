class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        map<int,int,greater<int>> mpp;
        int n = x.size();
        for(int i = 0; i<n; i++) {
            mpp[x[i]] = max(mpp[x[i]],y[i]);
        }
        if(mpp.size() < 3) return -1;
        priority_queue<int,vector<int>,greater<int>> q;
        int sum = 0;
        for(auto i: mpp) {
            if(q.size() < 3) {
                q.push(i.second);
                sum += i.second;
            }
            else if(q.top() < i.second) {
                sum -= q.top();
                q.pop();
                sum += i.second;
                q.push(i.second);
            }
        }
        return sum;
    }
};