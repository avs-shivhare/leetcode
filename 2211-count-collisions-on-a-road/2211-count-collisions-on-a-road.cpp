class Solution {
public:
    int countCollisions(string s) {
        int l = 0,r = s.size()-1;
        int ans = 0;
        while(l<=r && s[l] == 'L') l++;
        while(l<=r && s[r] == 'R') r--;
        while(l<=r) {
            if(s[l] == 'L' || s[l] == 'R') ans++;
            l++;
        }
        return ans;
    }
};