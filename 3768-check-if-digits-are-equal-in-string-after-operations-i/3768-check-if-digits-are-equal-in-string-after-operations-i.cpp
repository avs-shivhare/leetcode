class Solution {
public:
    bool hasSameDigits(string s) {

        while (true) {
            if(s.size() == 2) {
                if(s[0] == s[1]) return true;
                return false;
            }
            string temp = "";
            for(int i = 1; i<s.size(); i++) {
                int sum = ((s[i-1]-'0')+(s[i]-'0'))%10;
                temp += (sum+'0');
            }
            s = temp;
        }
        return false;
    }
};