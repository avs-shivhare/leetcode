class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> mpp;
        for(auto i: s) {
            mpp[i]++;
        }
        priority_queue<int,vector<int>,greater<int>> q;
        int cnt = 0;
        for(auto i: mpp) {
            if(q.size() < k) q.push(i.second);
            else if(q.top() < i.second) {
                cnt += q.top();
                q.pop();
                q.push(i.second);
            }
            else cnt += i.second;
        }
        return cnt;
    }
};