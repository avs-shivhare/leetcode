class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 1;
        char x = '1';
        int ans = 1;
        for(auto i: word) {
            if(x == i) cnt++;
            else {
                ans += cnt-1;
                cnt = 1;
                x = i;
            }
        } 
        ans += cnt-1;
        return ans;
    }
};