class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mpp;
        for(auto i: word) {
            mpp[i]++;
        }
        priority_queue<pair<int,char>> q;
        int ans = 0;
        for(auto i: mpp) {
            q.push({i.second,i.first});
        }
        int i =0;
        while(!q.empty()) {
            ans +=(q.top().first*((i/8)+1));
            q.pop();
            i++;
        }
        return ans;
    }
};