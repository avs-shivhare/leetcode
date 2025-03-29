class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> left(n,0),right(n,0);
        vector<int> lleft(n,0),lright(n,0);
        int zero = 0;
        int one = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == '0') {
                zero++;
            }
            else {
                left[i] = zero;
                zero = 0;
            }
            if(s[i] == '1') {
                one++;
            }
            else{
                lleft[i] = one;
                one = 0;
            }
        }
        zero = 0;
        one = 0;
        int total = 0;
        int ans = 0;
        for(int i = n-1; i>=0; i--) {
            if(s[i] == '0') zero++;
            else {
                right[i] = zero;
                zero = 0;
            }
            if(s[i] == '1') {
                one++;
                total++;
            }
            else {
                lright[i] = one;
                one = 0;
            }
        }
        int l = 0,r = 0;
        int cnt = 0;
        ans = total;
        while(r<n) {
            if(s[r] == '0') cnt++;
            while(l<r && cnt > 0) {
                if(s[l] == '0') cnt--;
                l++;
            }
            if(cnt == 0) {
                if(left[l] != 0 && right[r] != 0) {
                    //cout<<total-(r-l+1)<<endl;
                    ans = max(total+left[l]+right[r],ans);
                }
            }
            r++;
        }
        return ans;
    }
};