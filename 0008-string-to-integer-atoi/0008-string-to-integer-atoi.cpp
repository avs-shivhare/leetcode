class Solution {
public:
    int myAtoi(string s) {
        double ans = 0;
        bool flag = true;
        int n = s.size();
        int i =0;
        while(i<n && s[i] == ' ') {
            i++;
        }
        if(i<n && (s[i] == '-' || s[i] == '+')) {
            if(s[i] == '+');
            else flag = false;
            i++;
        } 
        for(;i<n; i++) {
            if(s[i] == '.') break;
            if('0'<=s[i] && s[i]<= '9') {
                ans = ans*10+(s[i]-'0');
            }
            else break;
        }
        if(flag == false) ans *= -1;
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};