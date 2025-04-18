class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 2; i<=n; i++) {
            string temp = "";
            char x = s[0];
            int cnt = 0;
            for(auto i: s) {
                if(x == i) cnt++;
                else {
                    temp += to_string(cnt);
                    temp += x;
                    x = i;
                    cnt = 1;
                }
            }
            temp += to_string(cnt);
            temp += x;
            s = temp;
        }
        return s;
    }
};