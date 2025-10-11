class Solution {
public:
    bool scoreBalance(string s) {
        long long sum = 0;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            sum += s[i]-'a'+1;
        }
        long long sum2 = 0;
        for(int i = 0; i<n-1; i++) {
            sum2 += s[i]-'a'+1;
            sum -= s[i]-'a'+1;
            if(sum == sum2) return true;
        }
        return false;
    }
};