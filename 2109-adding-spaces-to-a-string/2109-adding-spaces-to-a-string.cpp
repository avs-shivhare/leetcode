class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = s.size();
        int m = spaces.size();
        int j = 0;
        int i = 0;
        while(i<n || j<m) {
            if(j<m && spaces[j] == i) {
                ans += " ";
                j++;
            }
            else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};