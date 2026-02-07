class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        //if(n == 1) return 0;
        int a = 0,b = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == 'a') a++;
        }
        //if(a == 0 || a == n) return 0;
        int ans = 1e9;
        for(int i = 0; i<n; i++) {
            ans = min(ans,a+b);
            //cout<<a<<" "<<b<<" "<<i<<endl;
            if(s[i] == 'a') a--;
            else b++;
            ans = min(ans,a+b);
        }
        return ans;
    }
};