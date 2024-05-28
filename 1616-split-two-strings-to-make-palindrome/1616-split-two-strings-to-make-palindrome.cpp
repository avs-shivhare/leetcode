class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0,r = s.size()-1;
        while(l<r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    bool check(string &a,string &b) {
        int l = 0,r = a.size()-1;
        while(l<r && a[l] == b[r]) {
            l++;
            r--;
        }
        if(l>= r) return true;
        return isPalindrome(a.substr(l,r-l+1)) || isPalindrome(b.substr(l,r-l+1));
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a,b) || check(b,a);
    }
};