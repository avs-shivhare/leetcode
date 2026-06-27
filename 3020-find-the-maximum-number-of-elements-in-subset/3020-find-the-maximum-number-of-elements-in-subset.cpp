class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> mpp;
        long long maxi = 0;
        for(auto &i: nums) {
            maxi = max(1ll*i,maxi);
            mpp[i]++;
        }
        int ans = 0;
        for(auto &i: mpp) {
            long long x = i.first;
            int cnt = 0;
            if(i.first == 1) {
                ans = max(ans,i.second);
                continue;
            }
            while(x <= maxi) {
                int val = 0;
                if(mpp.find(x) != mpp.end()) {
                    if(mpp[x] >= 2) {
                        val += 2;
                    }
                    else {
                        val++;
                    }
                }
                cnt += val;
                if(val <= 1) break;
                x *= x;
            }
            ans = max(ans,cnt);
        }
        if((ans&1) == 0) ans--;
        return max(1,ans);
    }
};