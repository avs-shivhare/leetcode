class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;
        int cnt = 0;
        for(auto &i: s) {
            if(i == '1') cnt++;
            else flag = true;
            if(flag && i == '1') return false;
        }
        return cnt > 0;
    }
};