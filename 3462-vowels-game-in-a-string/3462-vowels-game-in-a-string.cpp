class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                cnt++;
            }
        }
        if(cnt && (cnt & 1) == 0) return true;
        else if(cnt & 1) return true;
        return false;
    }
};