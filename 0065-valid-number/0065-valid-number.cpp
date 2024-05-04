class Solution {
public:
    bool isNumber(string s) {
        bool digit = false,E = false,dot = false;
        int cnt = 0;
        int n= s.size();
        for(int i =0; i<n; i++) {
            if('0'<= s[i] && s[i] <= '9') {
                digit = true;
            }
            else if(s[i] == '+' || s[i] == '-') {
                if(cnt == 2) return false;
                if(i>0 && toupper(s[i-1]) != 'E') return false;
                if(i == n-1) return false;
                cnt++;
            }
            else if(toupper(s[i]) == 'E') {
                if(E || !digit) return false;
                if(i == n-1) return false;
                E = true;
            }
            else if(s[i] == '.') {
                if( i == n-1 && !digit) return false;
                if(E || dot) return false;
                dot = true;
            }
            else return false;
        }
        return true;
    }
};