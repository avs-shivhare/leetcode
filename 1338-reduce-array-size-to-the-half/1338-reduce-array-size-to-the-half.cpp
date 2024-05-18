class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(auto i: arr) {
            mpp[i]++;
        }
        int n = arr.size();
        int x = 0;
        int cnt = 0;
        n /=2;
        priority_queue<int> q;
        for(auto i: mpp) {
            q.push(i.second);
        }
        while(!q.empty()) {
            x += q.top();
            q.pop();
            cnt++;
            if(x >= n) return cnt;
        }
        return cnt;
    }
};