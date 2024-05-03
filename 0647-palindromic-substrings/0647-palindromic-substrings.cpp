class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for(int i =0; i<n; i++) {
            // odd length substring 
            int left = i,right = i;
            while(left >= 0 && right<n && s[left] == s[right]) {
                ans++;
                left--;
                right++;
            }

            //even length substring
            left = i,right = i+1;
            while(left >=0 && right <n && s[left] == s[right]) {
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};