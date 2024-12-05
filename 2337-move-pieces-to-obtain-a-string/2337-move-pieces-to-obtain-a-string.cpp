class Solution {
public:
    bool canChange(string start, string target) {
        int cnt = 0;
        int n = start.size();
        int l= 0,r = 0;
        for(auto i: start) {
            if(i == 'L') l++;
            else if(i == 'R') r++;
        }
        for(auto i: target) {
            if(i == 'L') l--;
            else if(i == 'R') r--;
        }
        if(l != 0 || r != 0) return false;
        for(int i = n-1; i>=0; i--) {
            if(start[i] == 'L') cnt++;
            if(start[i]== 'R') cnt = 0;
            if(target[i] == 'L') {
                if(cnt >= 1) cnt--;
                else return false;
            }
            else if(target[i] == 'R') {
                if(cnt != 0) return false;
            }
        }
        if(cnt != 0) return false;
        cnt = 0;
        for(int i = 0; i<n; i++) {
            if(start[i] == 'R') cnt++;
            if(start[i] == 'L') cnt = 0;
            if(target[i] == 'R') {
                if(cnt >= 1) cnt--;
                else return false;
            }
            else if(target[i] == 'L') {
                if(cnt != 0) return false;
            }
        }
        if(cnt != 0) return false;
        return true;
    }
};