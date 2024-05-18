class Solution {
public:
    string breakPalindrome(string pal) {
        int n = pal.size();
        if(n == 1) return "";
        int l = 0,r = n-1;
        while(l<r && pal[l] == pal[r] && pal[l] == 'a') {
            l++;
            r--;
        }
        if(l<r) pal[l] = 'a';
        else {
            pal[n-1] = 'b';
        }
        return pal;
    }
};