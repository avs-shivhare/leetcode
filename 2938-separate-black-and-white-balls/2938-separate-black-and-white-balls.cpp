class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt =0,ans =0;
        for(auto i: s) {
            if(i == '1') cnt++;
            else {
                ans += cnt;
            }
        }
        return ans;
    }
};