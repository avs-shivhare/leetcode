class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<long long,int> mpp;
        for(int i = 1; i<min(1000,n); i++) {
            for(int j = i; j<min(1000,n); j++) {
                long long p = (1ll*i*i*i)+(1ll*j*j*j);
                if(p > n) break;
                mpp[p]++;
            }
        }
        vector<int> ans;
        for(auto &i: mpp) {
            if(i.first <= n && i.second > 1) {
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};