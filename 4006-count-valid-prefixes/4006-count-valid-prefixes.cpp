class Solution {
public:
    int countValidPrefixes(string s) {
        int one = 0,zero = 0;
        int cnt = 0;
        for(auto &i: s) {
            if(i == '0') zero++;
            else one++;
            if(abs(one-zero) <= 1) cnt++;
        }
        return cnt;
    }
};