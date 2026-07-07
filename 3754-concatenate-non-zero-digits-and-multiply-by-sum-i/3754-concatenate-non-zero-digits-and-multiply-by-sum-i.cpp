class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string s = to_string(n);
        string ans = "";
        for(auto &i: s) {
            if(i != '0') ans += i;
            sum += i-'0';
        } 
        if(ans.empty()) return 0;
        return sum*stoll(ans);
    }
};