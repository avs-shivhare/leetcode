class Solution {
public:
    bool prime(long long n) {
        if(n <=1) return false;
        for(long long i = 2; i*i<=n; i++) {
            if(n%i == 0) return false;
        }
        return true;
    }
    bool completePrime(int num) {
        string s = to_string(num);
        for(int i = 0; i<s.size(); i++) {
            string t = s.substr(0,i+1);
            if(!prime(stoll(t))) return false;
        }
        for(int i = s.size()-1; i>=0; i--) {
            string t = s.substr(i);
            if(!prime(stoll(t))) return false;
        }
        return true;
    }
};