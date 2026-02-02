class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();
        int l = 0,r = n-1;
        while(l<r) {
            if('a' <= s[l] && s[l] <= 'z' && 'a' <= s[r] && s[r] <= 'z') {
                swap(s[l],s[r]);
                l++;
                r--;
            }
            if(s[l] > 'z' || s[l] < 'a') l++;
            if(s[r] > 'z' || s[r] < 'a') r--;
        }
        l = 0,r = n-1;
        while(l<r) {
            if((s[l] > 'z' || s[l] < 'a') && (s[r] > 'z' || s[r] < 'a')) {
                swap(s[l],s[r]);
                l++;
                r--;
            }
            if('a' <= s[l] && s[l] <= 'z') l++;
            if('a' <= s[r] && s[r] <= 'z') r--;
        }
        return s;
    }
};