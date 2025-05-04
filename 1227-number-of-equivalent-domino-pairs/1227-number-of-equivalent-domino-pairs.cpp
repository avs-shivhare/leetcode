class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> mpp;
        int cnt = 0;
        for(auto i: dominoes) {
            sort(i.begin(),i.end());
            cnt += mpp[{i[0],i[1]}];
            mpp[{i[0],i[1]}]++;
        }
        return cnt;
    }
};