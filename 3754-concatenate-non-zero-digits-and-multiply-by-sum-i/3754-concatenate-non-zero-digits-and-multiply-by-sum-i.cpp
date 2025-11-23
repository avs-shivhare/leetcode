class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string temp = "";
        long long sum = 0;
        for(auto i: s) {
            if(i != '0') {
                temp += i;
                sum += i-'0';
            }
        }
        if(temp.empty()) return 0;
        long long ans = stoll(temp)*sum;
        return ans;
    }
};