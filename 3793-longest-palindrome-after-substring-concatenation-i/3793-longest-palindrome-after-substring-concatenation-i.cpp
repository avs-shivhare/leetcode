class Solution {
public:
    bool find(string &s) {
        int l = 0,r = s.size()-1;
        while(l<r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        unordered_set<string> st,st2;
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            string temp ="";
            for(int j = i; j<n; j++) {
                temp += s[j];
                st.insert(temp);
                if(find(temp)) {
                    ans = max(ans,(int)temp.size());
                }
            }
        }
        n = t.size();
        for(int i = 0; i<n; i++) {
            string temp = "";
            for(int j = i; j<n; j++) {
                temp += t[j];
                st2.insert(temp);
                if(find(temp)) {
                    ans = max(ans,(int)temp.size());
                }
            }
        }
        for(auto i: st) {
            for(auto j: st2) {
                string temp = i+j;
                if(find(temp)) {
                    ans = max(ans,(int)temp.size());
                }
            }
        }
        return ans;
    }
};