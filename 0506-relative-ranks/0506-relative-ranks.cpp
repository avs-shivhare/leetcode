class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int,int,greater<int>> mpp;
        int n = score.size();
        for(int i =0; i<n; i++) {
            mpp[score[i]] =i;
        }
        vector<string> ans(n);
        int j = 1;
        for(auto i: mpp) {
            if(j == 1) {
                ans[i.second] = "Gold Medal";
            }
            else if(j == 2) {
                ans[i.second] = "Silver Medal";
            }
            else if(j == 3) {
                ans[i.second] = "Bronze Medal";
            }
            else {
                ans[i.second] = to_string(j);
            }
            j++;
        }
        return ans;
    }
};