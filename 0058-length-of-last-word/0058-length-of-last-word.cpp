class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i =n-1;
        int ans =0;
        while(i>=0 && s[i] == ' ') i--;
        int start =i;
        while(i>=0 && s[i] != ' ') i--;
        ans = start-i;
        return ans;
    }
};