class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            mpp[nums[i]].push_back(i);
        }
        vector<long long> ans(n,0);
        for(auto &i: mpp) {
            if(i.second.size() == 1) continue;
            int m = i.second.size();
            vector<long long> prefix(m,0),suffix(m,0);
            for(int j = 1; j<m; j++) {
                prefix[j] = (1ll*i.second[j]-i.second[j-1])*j;
                prefix[j] += prefix[j-1];
            }
            for(int j = m-2; j>=0; j--) {
                suffix[j] = (1ll*i.second[j+1]-i.second[j])*(m-j-1);
                suffix[j] += suffix[j+1];
            }
            for(int j = 0; j<m; j++) {
                ans[i.second[j]] = prefix[j]+suffix[j];
            }
        }
        return ans;
    }
};