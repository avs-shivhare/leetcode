class Solution {
public:
    bool find(int n) {
        string s = "";
        while(n) {
            if(n&1) s += '1';
            else s += '0';
            n = n>>1;
        }
        for(int i = 1; i<s.size(); i++) {
            if(s[0] != s[i]) return false;
        }
        return true;
    }
    int countMonobit(int n) {
        int cnt = 0;
        for(int i = 0; i<=n; i++) {
            if(find(i)) cnt++;
        }
        return cnt;
    }
};