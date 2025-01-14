class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> mpp,mpp2;
        int n = a.size();
        int cnt = 0;
        vector<int> ans;
        for(int i = 0; i<n; i++) {
            mpp[a[i]]++;
            mpp2[b[i]]++;
            for(auto &j: mpp) {
                if(j.second == 0) continue;
                if(mpp2.count(j.first)) {
                    int val = min(j.second,mpp2[j.first]);
                    j.second -= val;
                    mpp2[j.first] -= val;
                    if(mpp2[j.first] == 0) mpp2.erase(j.first);
                    cnt += val;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};