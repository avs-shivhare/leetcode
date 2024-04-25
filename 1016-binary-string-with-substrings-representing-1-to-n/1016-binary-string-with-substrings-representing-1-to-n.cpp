class Solution {
public:
    string binary(int n) {
        string ans = "";
        while(n) {
            ans = to_string(n%2)+ans;
            n /=2;
        }
        return ans;
    }
    bool queryString(string s, int n) {
        for(int i =1; i<=n; i++) {
            string temp = binary(i);
            if(s.find(temp) == string::npos) return false;
        }
        return true;
    }
};