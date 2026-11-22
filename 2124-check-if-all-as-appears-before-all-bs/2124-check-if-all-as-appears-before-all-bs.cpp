class Solution {
public:
    bool checkString(string s) {
        int cnt = 0;
        for(auto &i: s) {
            if(i == 'b') cnt++;
            else if(cnt) return false;
        }
        return true;
    }
};