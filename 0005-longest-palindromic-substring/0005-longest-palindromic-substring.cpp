class Solution {
public:
    // bool isPalindrome(string s) {
    //     //cout<<s<<endl;
    //     int i =0,j = s.size()-1;
    //     while(i<j) {
    //         if(s[i] != s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        int maxi = 0;
        int st = 0,end = 0;
        //odd palindrome case
        for(int i =0; i<n; i++) {
            int l = i,r = i;
            while(l>=0 && r<n && s[l] == s[r]) {
                l--;
                r++;
            }
            if(maxi < r-l-1) {
                maxi = r-l-1;
                st = l+1;
                end = r-1;
            }
        }
        //even palindrome case
        for(int i =0; i<n; i++) {
            int l = i,r = i+1;
            while(l>=0 && r<n && s[l] == s[r]) {
                l--;
                r++;
            }
            if(maxi < r-l-1) {
                maxi = r-l-1;
                st = l+1;
                end = r-1;
            }
        }
        return s.substr(st,end-st+1);
    }
};