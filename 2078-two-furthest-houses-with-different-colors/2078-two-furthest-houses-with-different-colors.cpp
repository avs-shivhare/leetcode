class Solution {
public:
    int maxDistance(vector<int>& colors) {
        unordered_map<int,int> mpp;
        int n = colors.size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(auto &j: mpp) {
                if(j.first != colors[i]) ans = max(ans,i-j.second);
            }
            if(mpp.find(colors[i]) == mpp.end()) mpp[colors[i]] = i;
        }
        return ans;
    }
};