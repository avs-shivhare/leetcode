class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        int m = s.size();
        int ans = 1e9;
        int match = 0,notMatch = 0;
        for(int i = 0; i<n; i++) {
            if(i&1) {
                if(s[i] == '1') notMatch++;
                else match++;
            }
            else {
                if(s[i] == '0') notMatch++;
                else match++;
            }
        }
        ans = min(ans,notMatch);
        //if(ans == 0) return ans;
        for(int i = n; i<m; i++) {
            int l = i-n;
            if(s[l] == '1') {
                match--;
            }
            else {
                notMatch--;
            }
            swap(match,notMatch);
            if(n&1) {
                if(s[i] == '0') {
                    notMatch++;
                }
                else {
                    match++;
                }
            }
            else {
                if(s[i] == '1') {
                    notMatch++;
                }
                else {
                    match++;
                }
            }
            //cout<<i<<" "<<match<<" "<<notMatch<<endl;
            ans = min(ans,notMatch);
        }
        //cout<<endl;
        match = 0,notMatch = 0;
        for(int i = 0; i<n; i++) {
            if(i&1) {
                if(s[i] == '0') notMatch++;
                else match++;
            }
            else {
                if(s[i] == '1') notMatch++;
                else match++;
            }
        }
        ans = min(ans,notMatch);
        //if(ans == 0) return ans;
        for(int i = n; i<m; i++) {
            int l = i-n;
            if(s[l] == '0') {
                match--;
            }
            else {
                notMatch--;
            }
            swap(match,notMatch);
            if(n&1) {
                if(s[i] == '1') {
                    notMatch++;
                }
                else {
                    match++;
                }
            }
            else {
                if(s[i] == '0') {
                    notMatch++;
                }
                else {
                    match++;
                }
            }
            //cout<<i<<" "<<match<<" "<<notMatch<<endl;
            ans = min(ans,notMatch);
        }
        return ans;
    }
};