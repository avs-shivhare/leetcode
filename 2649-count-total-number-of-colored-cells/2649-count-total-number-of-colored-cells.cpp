class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 0;
        long long cnt = n;
        while(cnt) {
            //cout<<ans<<" "<<cnt<<endl;
            ans += (cnt*2)-1;
            cnt--;
        }
        ans *=2;
        //cout<<ans<<endl;
        ans -= ((long long)n*(long long)2)-1;
        return ans;
    }
};