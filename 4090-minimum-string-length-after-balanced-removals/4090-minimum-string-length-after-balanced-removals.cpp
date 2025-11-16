class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int cnt = 0,cnt1 = 0;
        for(auto i: s) {
            if(i == 'a') cnt++;
            else cnt1++;
        }
        return abs(cnt-cnt1);
    }
};