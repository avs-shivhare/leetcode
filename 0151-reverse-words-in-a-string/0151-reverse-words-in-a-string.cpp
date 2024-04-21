class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int prev = 0;
        int i =0;
        while(i<n && s[i] == ' ') i++;
        prev = i;
        while(i<n) {
            if(s[i] == ' ' ) {
                ans = s.substr(prev,i-prev)+" "+ans;
                while(i<n && s[i] == ' ') i++;
                prev = i;
            }
            if(i == n-1 && s[i] != ' ') {
                ans = s.substr(prev,i-prev+1)+" "+ans;
            }
            i++;
        }
        if(!ans.empty()) ans.erase(ans.end()-1);
        return ans;
    }
};