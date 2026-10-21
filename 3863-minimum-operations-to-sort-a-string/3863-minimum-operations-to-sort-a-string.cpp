class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n <= 1) return 0;
        else if(n == 2) {
            if(s[0] <= s[1]) return 0;
            return -1;
        }
        int sp = 0,lp = n-1;
        for(int i = 0; i<n; i++) {
            if(s[sp] > s[i]) sp = i;
            if(s[lp] <= s[i]) lp = i;
        }
        string t = s;
        sort(t.begin(),t.end());
        if(s == t) return 0;
        //cout<<sp<<" "<<lp<<endl;
        int cnt = 0;
        if(sp != 0) cnt++;
        if(lp != n-1) cnt++;
        if(sp == n-1 && lp == 0) cnt++;
        return max(1,cnt);
    }
};