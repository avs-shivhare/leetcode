class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int cntA = 0,cntB = 0,cntC = 0;
        map<pair<int,char>,int> prefix;
        for(int i =0; i<n; i++) {
            if(s[i] == 'a') {
                if(cntA < k) {
                    cntA++;
                    prefix[{cntA,'a'}] = i+1;
                }
            }
            else if(s[i] == 'b') {
                if(cntB < k) {
                    cntB++;
                    prefix[{cntB,'b'}] = i+1;
                }
            }
            else {
                if(cntC < k) {
                    cntC++;
                    prefix[{cntC,'c'}] = i+1;
                }
            }
        }
        if(cntA < k || cntB < k || cntC < k) return -1;
        if(k == 0) return 0;
        cntA = 0;
        cntB =0;
        cntC = 0;
        int ans = max({prefix[{k,'a'}],prefix[{k,'b'}],prefix[{k,'c'}]});
        for(int i =n-1; i>=0; i--) {
            bool flag = false;
            if(s[i] == 'a') {
                if(cntA < k) {
                    flag = true;
                    cntA++;
                }
            }
            else if(s[i] == 'b') {
                if(cntB < k) {
                    flag = true;
                    cntB++;
                }
            }
            else {
                if(cntC < k) {
                    flag = true;
                    cntC++;
                }
            }
            if(flag) {
                int temp = max({prefix[{k-cntA,'a'}],prefix[{k-cntB,'b'}],prefix[{k-cntC,'c'}]});
                ans = min(ans,temp+n-i);
            }
        }
        return ans;
    }
};