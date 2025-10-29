class Solution {
public:
    int smallestNumber(int n) {
        int cnt = 0;
        while(n) {
            cnt++;
            n >>= 1;
        }
        //cout<<cnt<<endl;
        int ans = 0;
        for(int i = 0; i<cnt; i++) {
            ans |= 1<<i;
            //cout<<ans<<endl;
        }
        return ans;
    }
};