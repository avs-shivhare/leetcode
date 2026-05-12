class Solution {
public:
    map<int,vector<pair<int,int>>,greater<int>> mpp;
    int minimumEffort(vector<vector<int>>& tasks) {
        for(auto &i: tasks) {
            mpp[i[1]-i[0]].push_back({i[1],i[0]});
        }
        int cnt = 0,sum = 0;
        for(auto &i: mpp) {
            sort(i.second.begin(),i.second.end(),greater<pair<int,int>>());
            for(auto &j: i.second) {
                if(sum < j.first) {
                    int diff = j.first-sum;
                    cnt += diff;
                    sum += diff;
                    sum -= j.second;
                }
                else {
                    sum -= j.second;
                }
            }
        }
        return cnt;
    }
};