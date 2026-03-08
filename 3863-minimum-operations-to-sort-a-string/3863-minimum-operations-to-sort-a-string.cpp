class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool flag = true;
        for(int i = 1; i<n; i++) {
            if(s[i-1] > s[i]) {
                flag = false;
                break;
            }
        }
        if(flag) return 0;
        if(n == 2) {
            return -1;
        }
        flag = true;
        bool flag2 = true;
        char first = s[0],last = s[n-1];
        for(int i = 0; i<n; i++) {
            if(first > s[i]) flag = false;
            if(last < s[i]) flag2 = false;
        }
        if(flag || flag2) return 1;
        flag = true,flag2 = true;
        for(int i = 0; i<n; i++) {
            if(i > 0 && first <= s[i]) {
                flag = false;
            }
            if(i < n-1 && last >= s[i]) {
                flag2 = false;
            }
            //cout<<flag<<" "<<flag2<<" "<<i<<endl;
        }
        if(flag && flag2) return 3;
        return 2;
    }
};