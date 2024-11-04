class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        char x = word[0];
        int cnt = 1;
        int n = word.size();
        for(int i =1; i<n; i++) {
            if(x == word[i] && cnt < 9) cnt++;
            else {
                ans += to_string(cnt)+x;
                cnt = 1;
                x = word[i];
            }
        }
        ans += to_string(cnt)+x;
        return ans;
    }
};