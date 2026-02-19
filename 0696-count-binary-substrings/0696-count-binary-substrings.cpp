class Solution {
public:
    int countBinarySubstrings(string s) {
        int last = 0;
        char el = '0';
        int cnt = 0,ans = 0;
        for(auto &i: s) {
            if(i == el) cnt++;
            else {
                el = i;
                last = cnt;
                cnt = 1;
            }
            if(cnt <= last) ans++;
        }
        return ans;
    }
};