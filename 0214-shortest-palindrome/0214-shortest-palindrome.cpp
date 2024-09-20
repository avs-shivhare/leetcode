class Solution {
public:
    vector<int> previous;
    void find(string &pattern) {
        int n = pattern.size();
        previous.resize(n,0);
        int len = 0,i =1;
        while(i<n) {
            if(pattern[len] == pattern[i]) {
                len++;
                previous[i] = len;
                i++;
            }
            else {
                if(len > 0) {
                    len = previous[len-1];
                }
                else i++;
            }
        }
    }
    string shortestPalindrome(string s) {
        string temp = s;
        reverse(temp.begin(),temp.end());
        string pattern = s+"#"+temp;
        find(pattern);
        int i = previous[pattern.size()-1];
        temp = s.substr(i);
        reverse(temp.begin(),temp.end());
        return temp+s;
    }
};