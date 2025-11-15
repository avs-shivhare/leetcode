class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> z;
        for(int i = 0; i<n; i++) {
            if(s[i] == '0') z.push_back(i);
        }
        int one = n-z.size();
        z.push_back(n);
        int ans = 0, sz = 0;
        for(int l = 0; l<n; l++) {
            for(int i = sz; i<z.size()-1; i++) {
                int c0 = i-sz+1;
                if(c0*c0 > one) break;
                int q = z[i+1];
                int p = z[i];
                int c1 = z[i]-l-(i-sz);
                if(c1 >= c0*c0) ans += q-p;
                else ans += max(q-p-(c0*c0-c1),0);
            }
            if(s[l] == '0') sz++;
            else {
                ans += z[sz]-l;
                one--;
            }
        }
        return ans;
    }
};