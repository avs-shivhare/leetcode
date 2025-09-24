class Solution {
public:
    string fractionToDecimal(int nn, int dd) {
        if(nn == 0) return "0";
        string ans = "";
        if((nn < 0) ^ (dd < 0)) ans += "-";
        long long n = labs(1ll*nn);
        long long m = labs(1ll*dd);
        ans += to_string(n/m);
        long long rem = n%m;
        if(rem == 0) return ans;
        ans += ".";
        unordered_map<int,int> mpp;
        while(rem) {
            if(mpp.find(rem) != mpp.end()) {
                ans.insert(mpp[rem],"(");
                ans += ")";
                return ans;
            }
            mpp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem/m);
            rem %= m;
        }
        return ans;
    }
};