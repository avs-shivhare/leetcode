class Solution {
public:
    long long find(string &s) {
        long long mod = 1e9+9;
        long long k = 31;
        long long hash = 0;
        long long pow = 1;

        int base = s[0] - 'a';

        for (int i = 0; i < s.size(); i++) {
            int diff = (s[i] - 'a' - base + 26) % 26;
            hash = (hash + (diff + 1) * pow) % mod;
            pow = (pow * k) % mod;
        }
        return hash;
    }
    long long countPairs(vector<string>& words) {
        long long ans = 0;
        unordered_map<long long,long long> mpp;
        for(auto &i: words) {
            long long temp = find(i);
            ans += mpp[temp];
            mpp[temp]++;
            //cout<<i<<" -> "<<temp<<endl;
        }
        return ans;
    }
};