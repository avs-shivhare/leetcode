class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string t = "balloon";
        unordered_map<char,int> mpp,mpp2;
        for(auto &i: text) mpp[i]++;
        for(auto &i: t) mpp2[i]++;
        int ans = 1e9;
        for(auto &i: mpp2) {
            ans = min(ans,mpp[i.first]/i.second);
        }
        return ans;
    }
};