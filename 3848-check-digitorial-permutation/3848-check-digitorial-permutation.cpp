class Solution {
public:
    bool isDigitorialPermutation(int n) {
        long long fact[10];
        memset(fact,0,sizeof(fact));
        fact[1] = 1;
        fact[0] = 1;
        for(int i = 2; i<10; i++) {
            fact[i] = fact[i-1]*i;
        }
        string s = to_string(n);
        sort(s.begin(),s.end());
        do {
            if(s[0] == '0') continue;
            long long sum = 0;
            for(auto &i: s) sum += fact[i-'0'];
            if(sum == stoll(s)) return true;
        }while(next_permutation(s.begin(),s.end()));
        return false;
    }
};