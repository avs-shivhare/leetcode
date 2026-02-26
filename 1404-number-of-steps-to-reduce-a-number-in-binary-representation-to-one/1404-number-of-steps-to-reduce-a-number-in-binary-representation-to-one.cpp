class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin(),s.end());
        int ans = 0;
        int i = 0;
        while(i<s.size()-1) {
            if(s[i] == '1') {
                int c = 1;
                for(int j = i; j<s.size(); j++) {
                    int sum = c+(s[j]-'0');
                    s[j] = sum%2+'0';
                    c = sum/2;
                    if(c == 0) break;
                }
                if(c) s.push_back('1');
            }
            else {
                i++;
            }
            ans++;
        }
        return ans;
    }
};