class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(char i: s) {
            mpp[i]++;
        }
        priority_queue<pair<int,char>> q;
        for(auto i: mpp) {
            q.push({i.second,i.first});
        }
        string ans = "";
        while(!q.empty()) {
            int cnt = q.top().first;
            char val = q.top().second;
            while(cnt--) {
                ans += val;
            }
            q.pop();
        }
        return ans;
    }
};