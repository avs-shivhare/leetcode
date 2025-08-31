class Solution {
public:
    int getLeastFrequentDigit(int n) {
        long long x = n;
        unordered_map<int,int> mpp;
        while(x != 0) {
            mpp[x%10]++;
            x /= 10;
        }
        int cnt = INT_MAX;
        int ans = INT_MAX;
        for(auto i: mpp) {
            if(i.second < cnt) {
                cnt = i.second;
                ans = i.first;
            }
            else if(i.second == cnt) ans = min(ans,i.first);
        }
        return ans;
    }
};