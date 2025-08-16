class Solution {
public:
    int maximum69Number (int num) {
        string x = to_string(num);
        int n = x.size();
        string ans = "";
        for(int i =0; i<n; i++) {
            string s = "";
            bool flag = true;
            for(int j = i; j<n; j++) {
                if(x[j] == '6' && flag) {
                    s += '9';
                    flag = false;
                }
                else s += x[j];
            }
            if(ans.size() < s.size()) ans = s;
            else if(ans.size() == s.size() && ans < s) s = ans;
        }
        return stoi(ans);
    }
};