class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int,int> mpp;
        for(auto i: ans) {
            mpp[i]++;
        }
        int res = 0;
        for(auto i: mpp) {
            res += ceil((double)i.second/(double)(i.first+1))*(i.first+1);
        }
        return res;
    }
};