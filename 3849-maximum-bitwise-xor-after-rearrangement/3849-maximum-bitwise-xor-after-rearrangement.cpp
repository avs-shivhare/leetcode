class Solution {
public:
    string maximumXor(string s, string t) {
        int zero = 0,one = 0;
        for(auto &i: t) {
            if(i == '0') zero++;
            else one++;
        }
        string ans = "";
        for(auto &i: s) {
            if(i == '1') {
                if(zero) {
                    ans += "1";
                    zero--;
                }
                else {
                    ans += "0";
                    one--;
                }
            }
            else {
                if(one) {
                    ans += "1";
                    one--;
                }
                else {
                    ans += "0";
                    zero--;
                }
            }
        }
        return ans;
    }
};