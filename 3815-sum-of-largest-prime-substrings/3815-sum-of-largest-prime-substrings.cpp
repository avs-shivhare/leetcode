class Solution {
public:
    bool prime(long long x) {
        if(x < 2) return false;
        for(long long i = 2; i*i<=x; i++) {
            if(x%i == 0) return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        set<long long,greater<long long>> st;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            string temp = "";
            for(int j = i; j<n; j++) {
                temp += s[j];
                st.insert(stoll(temp));
            }
        }
        int cnt = 0;
        long long ans = 0;
        for(auto i: st) {
            if(cnt == 3) break;
            if(prime(i)) {
                cnt++;
                ans += i;
            }
        }
        return ans;
    }
};